#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <random>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("./database/database.db");
    DB.open();

    // 选择数据库里最先创建的表
    QSqlQuery firstTable("SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%' ORDER BY ROWID ASC LIMIT 1");
    firstTable.next();
    currentTable = firstTable.value(0).toString();  // 为setupModel设置参数
    showWordAndParaphrase();
    startTimer();
}

MainWindow::~MainWindow() {
    delete ui;
    DB.close();
}

// 定时器
void MainWindow::startTimer() {
    QObject::disconnect(&timer, &QTimer::timeout, nullptr, nullptr);
    timer.setInterval(ui->interval->value() * 1000);
    QObject::connect(&timer, &QTimer::timeout, this, [this]() { MainWindow::showWordAndParaphrase(); });
    timer.start();
}

// 显示单词和释义
void MainWindow::showWordAndParaphrase() {
    QSqlQuery query;
    if (!query.exec(QString("SELECT COUNT(*) FROM \"%1\"").arg(currentTable)) || !query.next()) {
        return;
    }
    int total = query.value(0).toInt();
    if (total <= 0) {
        return;  // 表里没数据时中断函数
    }

    // 生成随机数
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, total-1);
    int ranNum = dis(gen);

    QString queryStr = QString("SELECT word, paraphrase FROM \"%1\" WHERE id = %2 AND isShow = 'true'").arg(currentTable).arg(ranNum);
    if (!query.exec(queryStr) || !query.next()) {
        return;
    }

    QString word = query.value(0).toString();
    QString paraphrase = query.value(1).toString();

    ui->word->setText(word);
    // 显示释义为真时显示释义
    if (showParaphrase) {
        ui->paraphrase->setText(paraphrase);
    }
    else {
        ui->paraphrase->clear();
    }
}

// 窗口缩放时改变文本大小
void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    adjustFontSize();
}

void MainWindow::adjustFontSize() {
    QFont font = ui->word->font();
    int width = this->size().width();
    int height = this->size().height();
    int fontSize = qMin(width, height) / 7;
    font.setPointSize(fontSize);
    ui->word->setFont(font);
    ui->paraphrase->setFont(font);
}

// 为子窗口传递数据库
QSqlDatabase MainWindow::getDatabaseConnection() const {
    return DB;
}

void MainWindow::on_settingBtn_clicked() {
    if (configWindow == nullptr) {
        configWindow = new settings(getDatabaseConnection());
        // 关闭子窗口后销毁子窗口,防止多次点击'设置按钮'出现多个设置窗口
        configWindow->setAttribute(Qt::WA_DeleteOnClose);
        configWindow->setWindowFlag(Qt::Window);

        // 传递子窗口选择的表给主窗口
        connect(configWindow, &settings::tableNameChanged, this, &MainWindow::updateTableName);

        // 主窗口点击'隐藏'按钮时更新子窗口tableview上'是否在主页面显示'列的按钮状态
        connect(this, &MainWindow::tableIsShowButtonStatement, configWindow, &settings::reloadIsShowButton);

        // 子窗口关闭后设置子窗口为空指针
        connect(configWindow, &QObject::destroyed, this, &MainWindow::onSettingsWindowClosed);
    }
    configWindow->show();
    configWindow->raise();
    configWindow->activateWindow();
}

// 子窗口关闭后指定为空指针
void MainWindow::onSettingsWindowClosed() {
    configWindow = nullptr;
}

// 子窗口点击下拉框选择新的单词表后更新用于随机显示单词的表
void MainWindow::updateTableName(const QString &tableName) {
    currentTable = tableName;
}

// 暂停
void MainWindow::on_pauseBtn_clicked() {
    if (timer.isActive()) {
        timer.stop();
    } else {
        timer.start();
    }
}

// 设置是否显示释义
void MainWindow::on_showParaphraseBtn_clicked(bool checked) {
    if (checked) {
        showParaphrase = true;
        QSqlQuery query;
        QString queryStr = QString("SELECT * FROM \"%1\" WHERE word = '%2'").arg(currentTable).arg(ui->word->text());
        query.exec(queryStr);

        while (query.next()) {
            QString word = query.value(1).toString();
            QString paraphrase = query.value(2).toString();
            ui->word->setText(word);
            ui->paraphrase->setText(paraphrase);
        }
    }
    else {
        showParaphrase = false;
        ui->paraphrase->clear();
    }
}

// 小数调整框的值改变时更改单词刷新时间
void MainWindow::on_interval_valueChanged(double arg1)
{
    timer.setInterval(arg1*1000);
    //暂停时如果小数调整框的值改变,将调用timer.start(),不用再次点击暂停键
    if(!timer.isActive()){
        timer.start();
    }
}

// 查找单词功能
void MainWindow::on_lineEdit_returnPressed() {
    if (ui->lineEdit->text().isEmpty()) {
        if(!timer.isActive()){
            timer.start();
        }

    }
    else {
        QSqlQuery query;
        QString queryStr = QString("SELECT * FROM \"%1\" WHERE word = '%2'").arg(currentTable, ui->lineEdit->text());
        query.exec(queryStr);

        if (!query.next()){
            return;
        }
        QString word = query.value(1).toString();
        QString paraphrase = query.value(2).toString();
        ui->word->setText(word);
        ui->paraphrase->setText(paraphrase);
        ui->pauseBtn->click();
        timer.stop();
    }
}

// 设置是否在主页面显示
void MainWindow::on_setShowingStateBtn_clicked() {
    QString currentWord = ui->word->text();
    if (currentWord.isEmpty() || currentTable.isEmpty()) {
        return;
    }

    QSqlQuery query;
    QString selectSql = QString("SELECT id,isShow FROM \"%1\" WHERE word = '%2'").arg(currentTable, currentWord);

    if (!query.exec(selectSql)) {
        return;
    }

    query.next();
    int id = query.value(0).toInt();

    // 子窗口没打开时直接在主窗口修改显示状态,因为子窗口的reloadIsShowButton函数要子窗口被创建才能调用
    if (configWindow != nullptr) {
        emit tableIsShowButtonStatement(id);
    } else {
        QSqlQuery update;
        QString newIsShow = (query.value(1).toString() == "true") ? "false" : "true";
        QString sql = QString("UPDATE \"%1\" SET isShow = '%2' WHERE word = '%3';").arg(currentTable, newIsShow, currentWord);
        if (!update.exec(sql)) {
            return;
        }
    }
}
