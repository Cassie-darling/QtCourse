/********************************************************************************
** Form generated from reading UI file 'qwmainwind.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWMAINWIND_H
#define UI_QWMAINWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWMainWind
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *controlPanel;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSetHeader;
    QHBoxLayout *hboxRowCount;
    QLabel *labRowCount;
    QSpinBox *spinBoxRowCount;
    QPushButton *btnSetRowCount;
    QPushButton *btnInitData;
    QPushButton *btnInsertRow;
    QPushButton *btnAppendRow;
    QPushButton *btnDelCurRow;
    QPushButton *btnAutoH;
    QPushButton *btnAutoV;
    QPushButton *btnReadToText;
    QCheckBox *chkTableEdit;
    QCheckBox *chkRowColor;
    QCheckBox *chkRowHeader;
    QCheckBox *chkColHeader;
    QRadioButton *radioRowSelect;
    QRadioButton *radioCellSelect;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QWMainWind)
    {
        if (QWMainWind->objectName().isEmpty())
            QWMainWind->setObjectName("QWMainWind");
        QWMainWind->resize(1000, 650);
        centralWidget = new QWidget(QWMainWind);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        controlPanel = new QWidget(splitter);
        controlPanel->setObjectName("controlPanel");
        verticalLayout = new QVBoxLayout(controlPanel);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnSetHeader = new QPushButton(controlPanel);
        btnSetHeader->setObjectName("btnSetHeader");

        verticalLayout->addWidget(btnSetHeader);

        hboxRowCount = new QHBoxLayout();
        hboxRowCount->setObjectName("hboxRowCount");
        labRowCount = new QLabel(controlPanel);
        labRowCount->setObjectName("labRowCount");

        hboxRowCount->addWidget(labRowCount);

        spinBoxRowCount = new QSpinBox(controlPanel);
        spinBoxRowCount->setObjectName("spinBoxRowCount");
        spinBoxRowCount->setMinimum(1);
        spinBoxRowCount->setMaximum(50);
        spinBoxRowCount->setValue(6);

        hboxRowCount->addWidget(spinBoxRowCount);

        btnSetRowCount = new QPushButton(controlPanel);
        btnSetRowCount->setObjectName("btnSetRowCount");

        hboxRowCount->addWidget(btnSetRowCount);


        verticalLayout->addLayout(hboxRowCount);

        btnInitData = new QPushButton(controlPanel);
        btnInitData->setObjectName("btnInitData");

        verticalLayout->addWidget(btnInitData);

        btnInsertRow = new QPushButton(controlPanel);
        btnInsertRow->setObjectName("btnInsertRow");

        verticalLayout->addWidget(btnInsertRow);

        btnAppendRow = new QPushButton(controlPanel);
        btnAppendRow->setObjectName("btnAppendRow");

        verticalLayout->addWidget(btnAppendRow);

        btnDelCurRow = new QPushButton(controlPanel);
        btnDelCurRow->setObjectName("btnDelCurRow");

        verticalLayout->addWidget(btnDelCurRow);

        btnAutoH = new QPushButton(controlPanel);
        btnAutoH->setObjectName("btnAutoH");

        verticalLayout->addWidget(btnAutoH);

        btnAutoV = new QPushButton(controlPanel);
        btnAutoV->setObjectName("btnAutoV");

        verticalLayout->addWidget(btnAutoV);

        btnReadToText = new QPushButton(controlPanel);
        btnReadToText->setObjectName("btnReadToText");

        verticalLayout->addWidget(btnReadToText);

        chkTableEdit = new QCheckBox(controlPanel);
        chkTableEdit->setObjectName("chkTableEdit");
        chkTableEdit->setChecked(true);

        verticalLayout->addWidget(chkTableEdit);

        chkRowColor = new QCheckBox(controlPanel);
        chkRowColor->setObjectName("chkRowColor");
        chkRowColor->setChecked(true);

        verticalLayout->addWidget(chkRowColor);

        chkRowHeader = new QCheckBox(controlPanel);
        chkRowHeader->setObjectName("chkRowHeader");
        chkRowHeader->setChecked(true);

        verticalLayout->addWidget(chkRowHeader);

        chkColHeader = new QCheckBox(controlPanel);
        chkColHeader->setObjectName("chkColHeader");
        chkColHeader->setChecked(true);

        verticalLayout->addWidget(chkColHeader);

        radioRowSelect = new QRadioButton(controlPanel);
        radioRowSelect->setObjectName("radioRowSelect");

        verticalLayout->addWidget(radioRowSelect);

        radioCellSelect = new QRadioButton(controlPanel);
        radioCellSelect->setObjectName("radioCellSelect");
        radioCellSelect->setChecked(true);

        verticalLayout->addWidget(radioCellSelect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter->addWidget(controlPanel);

        horizontalLayout->addWidget(splitter);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);

        horizontalLayout->addWidget(tableWidget);

        QWMainWind->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QWMainWind);
        mainToolBar->setObjectName("mainToolBar");
        QWMainWind->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QWMainWind);
        statusBar->setObjectName("statusBar");
        QWMainWind->setStatusBar(statusBar);

        retranslateUi(QWMainWind);

        QMetaObject::connectSlotsByName(QWMainWind);
    } // setupUi

    void retranslateUi(QMainWindow *QWMainWind)
    {
        QWMainWind->setWindowTitle(QCoreApplication::translate("QWMainWind", "QTableWidget\347\232\204\344\275\277\347\224\250", nullptr));
        btnSetHeader->setText(QCoreApplication::translate("QWMainWind", "\350\256\276\347\275\256\350\241\250\345\244\264", nullptr));
        labRowCount->setText(QCoreApplication::translate("QWMainWind", "\350\256\276\347\275\256\350\241\214\346\225\260", nullptr));
        btnSetRowCount->setText(QCoreApplication::translate("QWMainWind", "\347\241\256\350\256\244", nullptr));
        btnInitData->setText(QCoreApplication::translate("QWMainWind", "\345\210\235\345\247\213\345\214\226\350\241\250\346\240\274\346\225\260\346\215\256", nullptr));
        btnInsertRow->setText(QCoreApplication::translate("QWMainWind", "\346\217\222\345\205\245\350\241\214", nullptr));
        btnAppendRow->setText(QCoreApplication::translate("QWMainWind", "\346\267\273\345\212\240\350\241\214", nullptr));
        btnDelCurRow->setText(QCoreApplication::translate("QWMainWind", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", nullptr));
        btnAutoH->setText(QCoreApplication::translate("QWMainWind", "\350\207\252\345\212\250\350\260\203\350\212\202\350\241\214\351\253\230", nullptr));
        btnAutoV->setText(QCoreApplication::translate("QWMainWind", "\350\207\252\345\212\250\350\260\203\350\212\202\345\210\227\345\256\275", nullptr));
        btnReadToText->setText(QCoreApplication::translate("QWMainWind", "\350\257\273\345\217\226\350\241\250\346\240\274\345\206\205\345\256\271\345\210\260\346\226\207\346\234\254", nullptr));
        chkTableEdit->setText(QCoreApplication::translate("QWMainWind", "\350\241\250\346\240\274\345\217\257\347\274\226\350\276\221", nullptr));
        chkRowColor->setText(QCoreApplication::translate("QWMainWind", "\351\227\264\351\232\224\350\241\214\345\272\225\350\211\262", nullptr));
        chkRowHeader->setText(QCoreApplication::translate("QWMainWind", "\346\230\276\347\244\272\350\241\214\350\241\250\345\244\264", nullptr));
        chkColHeader->setText(QCoreApplication::translate("QWMainWind", "\346\230\276\347\244\272\345\210\227\350\241\250\345\244\264", nullptr));
        radioRowSelect->setText(QCoreApplication::translate("QWMainWind", "\350\241\214\351\200\211\346\213\251", nullptr));
        radioCellSelect->setText(QCoreApplication::translate("QWMainWind", "\345\215\225\345\205\203\346\240\274\351\200\211\346\213\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QWMainWind", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QWMainWind", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QWMainWind", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QWMainWind", "\346\260\221\346\227\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QWMainWind", "\345\210\206\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("QWMainWind", "\346\230\257\345\220\246\345\205\232\345\221\230", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("QWMainWind", "\345\267\245\345\205\267\346\240\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWMainWind: public Ui_QWMainWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWMAINWIND_H
