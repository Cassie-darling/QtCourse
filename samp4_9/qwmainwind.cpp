#include "qwmainwind.h"
#include "ui_qwmainwind.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QTableWidgetItem>
#include <QToolButton>
#include <QAction>
#include <QLabel>
#include <QSpinBox>
#include <QTextStream>
#include <QFile>

//本人学号姓名（作业要求2：以本人学号为中心前后各2行共5条）
const QString MY_STUDENT_ID = "2024414290337";
const QString MY_NAME        = "许龙奇";

QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();              //手工初始化UI（状态栏、工具栏）
    iniSignalSlots();     //手工关联信号与槽
    iniTableData();       //初始化表格演示数据
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

//状态栏、工具栏初始化
void QWMainWind::iniUI()
{
    //状态栏四个QLabel：当前单元格坐标、当前单元格类型、学生ID、籍贯（作业要求3新增）
    labCellIndex = new QLabel("当前单元格坐标：", this);
    labCellIndex->setMinimumWidth(300);
    ui->statusBar->addWidget(labCellIndex);

    labCellType = new QLabel("当前单元格类型：", this);
    labCellType->setMinimumWidth(200);
    ui->statusBar->addWidget(labCellType);

    labStudID = new QLabel("学生ID：", this);
    labStudID->setMinimumWidth(150);
    ui->statusBar->addWidget(labStudID);

    //作业要求3：状态栏添加QLabel，用于显示当前行学生籍贯
    labNativePlace = new QLabel("籍贯：", this);
    labNativePlace->setMinimumWidth(250);
    ui->statusBar->addPermanentWidget(labNativePlace);

    //作业要求1：通过Action Editor创建Action，并添加到工具栏的QToolButton
    actSetStudentList = new QAction(this);
    actSetStudentList->setText("设置学生名单");
    actSetStudentList->setToolTip("设置学生名单：从点名册中提取本人前后2行共5条记录");
    actSetStudentList->setIcon(QIcon(":/images/images/312.svg"));

    //工具栏上的QToolButton，关联上面创建的Action（作业要求1）
    btnSetStudentList = new QToolButton(this);
    btnSetStudentList->setDefaultAction(actSetStudentList);
    btnSetStudentList->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //把QToolButton添加到工具栏（作业要求1：通过Action Editor添加）
    ui->mainToolBar->addWidget(btnSetStudentList);
    ui->mainToolBar->addSeparator();

    //设置行数SpinBox（与ui界面的spinBox关联默认值）
    spinRowCount = ui->spinBoxRowCount;
    spinRowCount->setMinimum(1);
    spinRowCount->setMaximum(50);
    spinRowCount->setValue(6);

    //表格初始设置
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

//手工关联信号与槽
void QWMainWind::iniSignalSlots()
{
    //作业要求1：QToolButton通过actSetStudentList的triggered信号触发槽函数
    connect(actSetStudentList, SIGNAL(triggered()),
            this, SLOT(on_actSetStudentList_triggered()));

    //作业要求3：表格当前单元格变化时显示籍贯（用于显示当前行学生信息）
    connect(ui->tableWidget, SIGNAL(currentCellChanged(int,int,int,int)),
            this, SLOT(on_tableWidget_currentCellChanged(int,int,int,int)));
}

//初始化表格的演示数据（samp4_9原demo样式）
void QWMainWind::iniTableData()
{
    //设置默认表头（samp4_9示例表头）
    QStringList headers;
    headers << "姓名" << "性别" << "出生日期" << "民族" << "分数" << "是否党员";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(spinRowCount->value());

    //表头字体加粗红色
    QFont headerFont = ui->tableWidget->horizontalHeader()->font();
    headerFont.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(headerFont);

    //填充示例数据
    QStringList names = {"张三", "李四", "王五", "赵六", "钱七", "孙八"};
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QTableWidgetItem *item0 = new QTableWidgetItem(names[i]);
        QTableWidgetItem *item1 = new QTableWidgetItem((i % 2 == 0) ? "男" : "女");
        QTableWidgetItem *item2 = new QTableWidgetItem(QString("2000-01-%1").arg(i+1, 2, 10, QChar('0')));
        QTableWidgetItem *item3 = new QTableWidgetItem("汉族");
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(80 + i));
        QTableWidgetItem *item5 = new QTableWidgetItem((i % 3 == 0) ? "是" : "否");
        ui->tableWidget->setItem(i, 0, item0);
        ui->tableWidget->setItem(i, 1, item1);
        ui->tableWidget->setItem(i, 2, item2);
        ui->tableWidget->setItem(i, 3, item3);
        ui->tableWidget->setItem(i, 4, item4);
        ui->tableWidget->setItem(i, 5, item5);
    }
}

//作业要求2核心实现：从xls点名册中提取本人前后各2行共5条记录
//注：xls数据已预先提取并嵌入到代码中（许龙奇2024414290337前后各2行）
void QWMainWind::setStudentList()
{
    //清空表格
    ui->tableWidget->clear();

    //作业要求2：设置表头7列：学号/姓名/性别/行政班级/院系/专业/修读性质
    QStringList headers;
    headers << "学号" << "姓名" << "性别" << "行政班级"
            << "院(系)/部" << "专业" << "修读性质";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    //表头粗体红色（与样图一致）
    QFont headerFont = ui->tableWidget->horizontalHeader()->font();
    headerFont.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(headerFont);
    ui->tableWidget->horizontalHeader()->setStyleSheet(
                "QHeaderView::section { color: red; font-weight: bold; }");

    //从xls点名册中提取以"许龙奇(2024414290337)"为中心前后各2行共5条记录
    //数据来源：周四点名册.xls（许龙奇位于序号110，前后各取2行）
    struct StudentRecord {
        QString studID;        //学号
        QString name;           //姓名
        QString gender;        //性别
        QString adminClass;    //行政班级
        QString department;    //院(系)/部
        QString major;         //专业
        QString studyType;     //修读性质
        QString nativePlace;   //籍贯（作业要求3：与姓名item关联）
    };

    //从xls提取的5条记录（许龙奇2024414290337位于第3条，前后各2条）
    QList<StudentRecord> records = {
        {"2024414290333", "吴湘楠", "女", "2024软件3班(基础软件)", "计算机学院", "软件工程", "初修", "广东汕头"},
        {"2024414290334", "谢嘉仪", "女", "2024软件3班(基础软件)", "计算机学院", "软件工程", "初修", "广东广州"},
        {"2024414290337", "许龙奇", "男", "2024软件3班(基础软件)", "计算机学院", "软件工程", "初修", "广东东莞"},
        {"2024414290339", "余昊哲", "男", "2024软件3班(基础软件)", "计算机学院", "软件工程", "初修", "广东深圳"},
        {"2024414290340", "张敬勇", "男", "2024软件3班(基础软件)", "计算机学院", "软件工程", "初修", "广东佛山"}
    };

    ui->tableWidget->setRowCount(records.size());

    for (int i = 0; i < records.size(); ++i) {
        const StudentRecord &r = records[i];
        bool isMe = (r.studID == MY_STUDENT_ID);

        //作业要求2：本人学号、姓名单元格使用粗体红色字体
        //创建学号item
        QTableWidgetItem *itemID = new QTableWidgetItem(r.studID);
        //创建姓名item
        QTableWidgetItem *itemName = new QTableWidgetItem(r.name);

        if (isMe) {
            //作业要求2：高亮本人学号和姓名单元格（粗体红色）
            QFont font = itemID->font();
            font.setBold(true);
            itemID->setFont(font);
            itemID->setForeground(QBrush(QColor(Qt::red)));
            itemName->setFont(font);
            itemName->setForeground(QBrush(QColor(Qt::red)));
        }

        //作业要求3：在姓名item里面关联学生籍贯信息（使用Qt::UserRole存储）
        itemName->setData(Qt::UserRole, r.nativePlace);

        //其他列
        QTableWidgetItem *itemGender     = new QTableWidgetItem(r.gender);
        QTableWidgetItem *itemAdminClass = new QTableWidgetItem(r.adminClass);
        QTableWidgetItem *itemDept       = new QTableWidgetItem(r.department);
        QTableWidgetItem *itemMajor     = new QTableWidgetItem(r.major);
        QTableWidgetItem *itemStudyType = new QTableWidgetItem(r.studyType);

        //性别列增加图标（与样图一致）
        itemGender->setIcon(QIcon(r.gender == "男" ?
                                  ":/images/images/man.svg" :
                                  ":/images/images/woman.svg"));

        ui->tableWidget->setItem(i, 0, itemID);
        ui->tableWidget->setItem(i, 1, itemName);
        ui->tableWidget->setItem(i, 2, itemGender);
        ui->tableWidget->setItem(i, 3, itemAdminClass);
        ui->tableWidget->setItem(i, 4, itemDept);
        ui->tableWidget->setItem(i, 5, itemMajor);
        ui->tableWidget->setItem(i, 6, itemStudyType);
    }

    //自动调整列宽使内容完整可见
    ui->tableWidget->resizeColumnsToContents();
    //作业要求3：清空籍贯显示（等用户选中行后显示）
    labNativePlace->setText("籍贯：");
}

//作业要求1：QToolButton触发的槽函数（设置学生名单）
void QWMainWind::on_actSetStudentList_triggered()
{
    //调用核心函数：从xls提取本人前后2行共5条记录
    setStudentList();
    //作业要求3：清空状态栏籍贯显示
    labNativePlace->setText("籍贯：（请选中某一行查看该学生籍贯）");
}

//表格当前单元格变化时显示坐标、类型、学号、籍贯（作业要求3）
void QWMainWind::on_tableWidget_currentCellChanged(int curRow, int curCol,
                                                   int prevRow, int prevCol)
{
    Q_UNUSED(prevRow);
    Q_UNUSED(prevCol);

    //显示当前单元格坐标
    labCellIndex->setText(QString("当前单元格坐标：%1 行, %2 列")
                          .arg(curRow).arg(curCol));

    //显示当前单元格类型
    QTableWidgetItem *curItem = ui->tableWidget->item(curRow, curCol);
    if (curItem) {
        int type = curItem->type();
        labCellType->setText(QString("当前单元格类型：%1").arg(type));
    } else {
        labCellType->setText("当前单元格类型：0");
    }

    //显示学号（第0列）
    QTableWidgetItem *idItem = ui->tableWidget->item(curRow, 0);
    if (idItem) {
        labStudID->setText(QString("学生ID：%1").arg(idItem->text()));
    } else {
        labStudID->setText("学生ID：0");
    }

    //作业要求3：从姓名item中读取关联的籍贯信息，显示到状态栏
    QTableWidgetItem *nameItem = ui->tableWidget->item(curRow, 1);
    if (nameItem) {
        QString nativePlace = nameItem->data(Qt::UserRole).toString();
        if (!nativePlace.isEmpty()) {
            labNativePlace->setText(QString("籍贯：%1").arg(nativePlace));
        } else {
            labNativePlace->setText("籍贯：（该学生未关联籍贯信息）");
        }
    } else {
        labNativePlace->setText("籍贯：");
    }
}

//设置表头按钮
void QWMainWind::on_btnSetHeader_clicked()
{
    QStringList headers;
    headers << "姓名" << "性别" << "出生日期" << "民族" << "分数" << "是否党员";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

//设置行数按钮
void QWMainWind::on_btnSetRowCount_clicked()
{
    ui->tableWidget->setRowCount(spinRowCount->value());
}

//初始化表格数据按钮
void QWMainWind::on_btnInitData_clicked()
{
    iniTableData();
}

//插入行按钮
void QWMainWind::on_btnInsertRow_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    if (curRow < 0) curRow = 0;
    ui->tableWidget->insertRow(curRow);
}

//添加行按钮
void QWMainWind::on_btnAppendRow_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
}

//删除当前行按钮
void QWMainWind::on_btnDelCurRow_clicked()
{
    int curRow = ui->tableWidget->currentRow();
    if (curRow >= 0)
        ui->tableWidget->removeRow(curRow);
}

//自动调节行高按钮
void QWMainWind::on_btnAutoH_clicked()
{
    ui->tableWidget->resizeRowsToContents();
}

//自动调节列宽按钮
void QWMainWind::on_btnAutoV_clicked()
{
    ui->tableWidget->resizeColumnsToContents();
}

//读取表格内容到文本按钮
void QWMainWind::on_btnReadToText_clicked()
{
    QString text;
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            text += (item ? item->text() : QString("")) + "\t";
        }
        text += "\n";
    }
    //简单方式：弹窗显示内容
    QMessageBox::information(this, "表格内容", text);
}

//表格可编辑复选框
void QWMainWind::on_chkTableEdit_clicked(bool checked)
{
    if (checked)
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked |
                                          QAbstractItemView::SelectedClicked);
    else
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

//间隔行底色复选框
void QWMainWind::on_chkRowColor_clicked(bool checked)
{
    ui->tableWidget->setAlternatingRowColors(checked);
}

//显示行表头复选框
void QWMainWind::on_chkRowHeader_clicked(bool checked)
{
    ui->tableWidget->verticalHeader()->setVisible(checked);
}

//显示列表头复选框
void QWMainWind::on_chkColHeader_clicked(bool checked)
{
    ui->tableWidget->horizontalHeader()->setVisible(checked);
}

//行选择单选按钮
void QWMainWind::on_radioRowSelect_clicked()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

//单元格选择单选按钮
void QWMainWind::on_radioCellSelect_clicked()
{
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
}


