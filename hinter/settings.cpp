#include "settings.h"
#include "ui_settings.h"

#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>


settings::settings(QSqlDatabase db, QWidget *parent)
    : QWidget(parent), ui(new Ui::settings), DB(db),
    model(new QSqlTableModel(this, DB))  // 初始化QSqlTableModel
{
    ui->setupUi(this);

    //添加表到combobox
    QSqlQuery QueryTable;
    QString sql = "SELECT name FROM sqlite_master WHERE TYPE = 'table' AND name NOT LIKE 'sqlite_%'";
    QueryTable.exec(sql);
    while(QueryTable.next()){
        ui->comboBox->addItem(QueryTable.value(0).toString());
    }

    // combobox中有表时,tableview显示第一张表
    if (ui->comboBox->count() > 0){
        ui->comboBox->setCurrentIndex(0);
    }
}

settings::~settings() { delete ui; }


void settings::setupModel(QString table_name) {
    if(isRefreshing) return;
    isRefreshing = true;


    model->setTable(table_name);
    model->setHeaderData(1, Qt::Horizontal, "单词");
    model->setHeaderData(2, Qt::Horizontal, "释义");
    model->setHeaderData(3, Qt::Horizontal, "是否在主页面显示");
    model->setHeaderData(4, Qt::Horizontal, "删除");
    model->select();


    // 加载全部数据到tableview,否则后面刷新的列不会有按钮
    while (model->canFetchMore()) {
        model->fetchMore();
    }

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0); // 隐藏表里的id列
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);  // 双击单元格进行编辑
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 设置表头宽度
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    // 序号居中显示
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

    // 添加按钮和空白行
    addIsShowButtonsToTable();
    addDeleteButtonsToTable();
    checkAndAddBlankRow();

    connect(model, &QAbstractItemModel::dataChanged, this, &settings::checkAndAddBlankRow);

    isRefreshing = false;
}

// 获取表里最大的id
int settings::getMaxId(const QString &tableName) {
    QSqlQuery query;
    QString sql = QString("SELECT MAX(id) FROM \"%1\"").arg(tableName);

    if (query.exec(sql) && query.next()) {
        return query.value(0).toInt();
    } else {
        return 0;
    }
}

// 检测最后一行是否是空行,不是的话添加空行
void settings::checkAndAddBlankRow() {
    int lastRow = model->rowCount() - 1;

    if (lastRow >= 0) {
        QString word = model->data(model->index(lastRow, 1)).toString();
        QString paraphrase = model->data(model->index(lastRow, 2)).toString();
        if (word.isEmpty() && paraphrase.isEmpty()) {
            return; // 最后一行是空行,不执行操作
        }
    }

    // 创建新行
    QSqlRecord record = model->record();
    // 为新行设置id
    int newId = getMaxId(model->tableName()) + 1;
    record.setValue("id", newId);
    record.setValue("word", "");
    record.setValue("paraphrase", "");
    record.setValue("isShow", "true");

    // 添加新行
    model->insertRecord(model->rowCount(), record);

    // 为新行添加按钮
    addIsShowButtonsToTable();
    addDeleteButtonsToTable();
}

// 添加是否在主页面显示按钮
void settings::addIsShowButtonsToTable() {
    int buttonColumn = 3; // 第三列
    for (int row = 0; row < model->rowCount(); ++row) {
        QString isShow = model->data(model->index(row, buttonColumn)).toString();
        QString isShowStatement = (isShow == "true") ? "是" : "否";
        QPushButton *button = new QPushButton(isShowStatement, ui->tableView);
        // 连接按钮点击信号
        connect(button, &QPushButton::clicked, this, [this, button, row]() {onIsShowButtonClicked(row, button);});

        // 添加按钮到单元格中
        ui->tableView->setIndexWidget(model->index(row, buttonColumn), button);
    }
}

// 按钮点击事件
void settings::onIsShowButtonClicked(int row, QPushButton* button) {
    QString word = model->data(model->index(row, 1)).toString();
    QString isShow = model->data(model->index(row, 3)).toString();

    QString newIsShow = (isShow == "true") ? "false" : "true";
    model->setData(model->index(row, 3), newIsShow);

    // 更新表里的显示状态
    QSqlQuery update;
    QString sql = QString("UPDATE \"%1\" SET isShow = '%2' WHERE word = '%3';").arg(model->tableName(), newIsShow, word);
    if (!update.exec(sql)) {
        return;
    }

    // 更新按钮文本
    QString newIsShowStatement = (newIsShow == "true") ? "是" : "否";
    button->setText(newIsShowStatement);
}

  // 添加删除按钮
void settings::addDeleteButtonsToTable() {
    int buttonColumn = 4; // 第四列
    for (int row = 0; row < model->rowCount(); ++row) {
        QPushButton *button = new QPushButton("删除", ui->tableView);

        // 连接按钮点击信号
        connect(button, &QPushButton::clicked, this, &settings::handleDeleteButtonClicked);

        // 添加按钮到单元格中
        ui->tableView->setIndexWidget(model->index(row, buttonColumn), button);
    }
}

// 按钮点击事件
void settings::handleDeleteButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // 获取被点击按钮所在行的索引
    for (int row = 0; row < model->rowCount(); ++row) {
        if (ui->tableView->indexWidget(model->index(row, 4)) == button) {
            // 删除被点击按钮所在行
            if (!model->removeRow(row)) {
                return;
            }

            if (!model->submitAll()) {
                return;
            }

            // 刷新tableview
            model->fetchMore();
            break;
        }
    }
}


// 查找功能
void settings::on_lineEdit_returnPressed() {
    if (isFilting){return;};
    isFilting = true;

    QString searchText = ui->lineEdit->text();
    // 将中文/英文输入法下的问号转换为通配符用于模糊查找
    searchText.replace("?", "_").replace("？", "_");
    // 输入框为空时清除过滤条件
    if (searchText.isEmpty()) {
        model->setFilter("");
    } else {
        // 模糊查找处理
        if (searchText.startsWith("'") && searchText.endsWith("'")) {
            searchText = searchText.mid(1, searchText.length() - 2);
        }
        model->setFilter(QString("word LIKE '%%1%'").arg(searchText));
    }
    model->select();
    // 一次性将所有数据读取到tableview上,否则惰性读取后面读取的行将没有按钮
    while (model->canFetchMore()) {
        model->fetchMore();
    }
    addIsShowButtonsToTable();  // 为查找的单词添加按钮
    addDeleteButtonsToTable();
    isFilting = false;
}

// 创建单词表
void settings::on_createTable_clicked()
{
    QInputDialog inputDialog;
    inputDialog.setWindowTitle("新建单词表");
    inputDialog.setLabelText("请输入单词表名称");

    inputDialog.setOkButtonText("确认");
    inputDialog.setCancelButtonText("取消");

    QString text;
    if (inputDialog.exec() == QDialog::Accepted && !inputDialog.textValue().isEmpty()) {
        text = inputDialog.textValue();

        QSqlQuery checkTableQuery;
        QString checkSql = QString("SELECT name FROM sqlite_master WHERE type='table' AND name=\"%1\";").arg(text);

        // 如果单词本已存在,中断函数
        if (checkTableQuery.exec(checkSql) && checkTableQuery.next()) {
            return;
        }

        QSqlQuery createTableQuery;

        QString createSql =
            QString("CREATE TABLE IF NOT EXISTS \"%1\" (id INTEGER PRIMARY KEY "
                    "AUTOINCREMENT,word TEXT, paraphrase TEXT, isShow TEXT "
                                    "DEFAULT 'true', delete_button NULL)").arg(text);

        if (createTableQuery.exec(createSql)) {
            // 添加表到combobox
            ui->comboBox->addItem(text);
            setupModel(text);
        } else {
            return;
        }
    }
}

// 下拉框选择表时传递选择的表给主窗口
void settings::on_comboBox_currentIndexChanged(int index) {
    if (index < 0) return;
    QString tableName = ui->comboBox->itemText(index);
    emit tableNameChanged(tableName);
    setupModel(tableName);
}


// 删除表
void settings::on_deleteTable_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("删除提示");
    msgBox.setText("你确定删除当前的单词表吗?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "确认");
    msgBox.setButtonText(QMessageBox::No, "取消");

    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());

    if (reply == QMessageBox::Yes) {
        // 获取正在显示的表
        QString current_table_name = model->tableName();
        QSqlQuery del_table;
        model->clear();
        QString sql = QString("DROP TABLE IF EXISTS \"%1\"").arg(current_table_name);
        del_table.exec(sql);

        // 从下拉框中移除删除的表
        ui->comboBox->removeItem(ui->comboBox->findText(current_table_name));
        // 删除表后选择最后创建的表来显示单词
        QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%' ORDER BY ROWID DESC LIMIT 1");
        if(!query.next()) return;
        QString tableName = query.value(0).toString();
        ui->comboBox->setCurrentText(tableName);
        setupModel(tableName);
    }
}

// 清空表
void settings::on_clearTable_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("清空提示");
    msgBox.setText("你确定清空当前的单词表吗?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "确认");
    msgBox.setButtonText(QMessageBox::No, "取消");

    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());

    if (reply == QMessageBox::Yes) {
        QSqlQuery clear_table;
        QString command = QString("DELETE FROM \"%1\"").arg(model->tableName());
        clear_table.exec(command);
        setupModel(model->tableName());
    }
}

// 刷新表
void settings::on_refreshButton_clicked() {
    ui->refreshButton->setEnabled(false); // 禁用按钮防止刷新完场前多次点击造成不必要的资源浪费

    setupModel(model->tableName());

    ui->refreshButton->setEnabled(true); // 刷新完成后重新启用按钮
}

// 刷新按钮显示状态
void settings::reloadIsShowButton(const int &row) {
    int buttonColumn = 3; // 是否显示在主页面按钮所在行
    QPushButton *button = qobject_cast<QPushButton*>(ui->tableView->indexWidget(model->index(row, buttonColumn)));

    if (!button) {
        return;
    }
    // 因为tableview索引从0开始,会比id大一,所以减一
    onIsShowButtonClicked(row-1, button);
}


