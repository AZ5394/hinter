#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QTimer>
#include <QWidget>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startTimer();  // 定时器功能,用于设置'随机显示单词'功能的调用时间间隔
    void showWordAndParaphrase();  // '随机显示单词'功能
    QSqlDatabase getDatabaseConnection() const;  // 获取当前主窗口连接的数据库,用于传递主窗口的数据库连接给子窗口

protected:
    void resizeEvent(QResizeEvent *event) override;
    void adjustFontSize();  // 缩放窗口时根据一定的比例调节字体大小,默认是长宽中的最小值除7
signals:
    void tableIsShowButtonStatement(const int &row);  // 点击主窗口的'显示释义'按钮时,更新子窗口的'是否在主页面显示'按钮的状态

private slots:
    void on_settingBtn_clicked();  // 打开设置页面
    void on_pauseBtn_clicked();  // 暂停按钮
    void on_showParaphraseBtn_clicked(bool checked);  // 是否显示释义按钮
    void on_interval_valueChanged(double arg1);  // 小数调整框的小数改变时,更改timer调用showWordAndParaphrase功能的时间间隔
    void on_lineEdit_returnPressed();  // 在输入框输入单词后回车,将显示查找的单词,不支持模糊查找,因为页面上只有两个label,如果再开一个窗口感觉太冗余了
    void on_setShowingStateBtn_clicked();  // 更改单词显示状态
    void updateTableName(const QString &tableName);  // 当子页面通过下拉框选择单词表时,主页面更新单词表,随机显示的单词将从子页面选择的单词表中抽取
    void onSettingsWindowClosed(); // 子窗口关闭后指定为空指针

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB;
    QTimer timer;
    bool showParaphrase = true;  // 默认显示释义
    QString currentTable;  // 设置默认单词表
    settings *configWindow = nullptr;

};

#endif // MAINWINDOW_H
