#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QAction>
#include <QToolButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>

namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT

private:
    QLabel      *labCellIndex;       //状态栏：显示当前单元格坐标
    QLabel      *labCellType;        //状态栏：显示当前单元格类型
    QLabel      *labStudID;          //状态栏：显示当前学生学号
    QLabel      *labNativePlace;     //状态栏：显示当前选中行的学生籍贯（作业要求3）

    QAction     *actSetStudentList;  //设置学生名单（作业要求1：工具栏添加QToolButton）
    QToolButton *btnSetStudentList;  //工具栏上的QToolButton，关联actSetStudentList

    QSpinBox    *spinRowCount;       //设置行数SpinBox

    void    iniUI();                 //手工初始化UI（状态栏与工具栏）
    void    iniSignalSlots();        //手工关联信号与槽
    void    iniTableData();          //初始化表格演示数据

    //作业要求2核心：从xls数据中提取以"许龙奇(2024414290337)"为中心前后各2行共5条记录
    void    setStudentList();

public:
    explicit QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private slots:
    //界面生成的槽函数（按钮）
    void on_btnSetHeader_clicked();         //设置表头
    void on_btnSetRowCount_clicked();       //设置行数
    void on_btnInitData_clicked();          //初始化表格数据
    void on_btnInsertRow_clicked();        //插入行
    void on_btnAppendRow_clicked();        //添加行
    void on_btnDelCurRow_clicked();        //删除当前行
    void on_btnAutoH_clicked();             //自动调节行高
    void on_btnAutoV_clicked();             //自动调节列宽
    void on_btnReadToText_clicked();       //读取表格内容到文本

    void on_chkTableEdit_clicked(bool checked);        //表格可编辑
    void on_chkRowColor_clicked(bool checked);         //间隔行底色
    void on_chkRowHeader_clicked(bool checked);        //显示行表头
    void on_chkColHeader_clicked(bool checked);        //显示列表头

    void on_radioRowSelect_clicked();      //行选择
    void on_radioCellSelect_clicked();     //单元格选择

    //表格交互
    void on_tableWidget_currentCellChanged(int curRow, int curCol,
                                           int prevRow, int prevCol);  //当前单元格变化
    //作业要求1：工具栏QToolButton触发的槽函数（设置学生名单）
    void on_actSetStudentList_triggered();

private:
    Ui::QWMainWind *ui;
};

#endif // QWMAINWIND_H
