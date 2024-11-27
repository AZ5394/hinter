#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QWidget>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class settings;
}


class settings : public QWidget {
    Q_OBJECT

public:
    explicit settings(QSqlDatabase db,
                      QWidget *parent = nullptr);
    ~settings();
    void setupModel(QString table_name);  // 更新tableview
    void addIsShowButtonsToTable();  // 添加是否显示按钮到tableview
    void addDeleteButtonsToTable();  // 添加删除按钮到tableview
    void checkAndAddBlankRow();  // 检查最后一行是否为空白行,是的话添加空白行
    int getMaxId(const QString &tableName);  // 获取表里最后一行的id,为新创建的行基于上一行id设置id

signals: void tableNameChanged(const QString &tableName);

private slots:
    void on_lineEdit_returnPressed();  // 搜索单词功能,支持模糊查找
    void on_createTable_clicked();  // 新建单词表
    void on_comboBox_currentIndexChanged(int index);  // 下拉框选择单词表时更新tableview显示的表
    void on_deleteTable_clicked();  // 删除单词表
    void on_clearTable_clicked();  // 清空单词表
    void handleDeleteButtonClicked();  // 删除某行数据
    void onIsShowButtonClicked(int row, QPushButton* button);  // 设置是否在主页面显示
    void on_refreshButton_clicked();  // 刷新

public slots:
    void reloadIsShowButton(const int &row); // 主页面点击隐藏时调用这个函数,属性按钮显示状态


private:
    Ui::settings *ui;
    QSqlDatabase DB;
    QSqlTableModel *model;
    bool isRefreshing = false;  // 设置setupModel刷新状态,当正在刷新时,再次点击刷新按钮将无法刷新当前表,防止资源浪费
    bool isFilting = false;  // 设置tableview刷新状态,当在输入框会车时,完成查找单词前再次按回车将无法查询单词,防止资源浪费
    QTimer timer;

};

#endif // SETTINGS_H
