/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QPushButton *createTable;
    QPushButton *deleteTable;
    QPushButton *clearTable;
    QPushButton *refreshButton;
    QTableView *tableView;

    void setupUi(QWidget *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName("settings");
        settings->resize(534, 284);
        horizontalLayout_2 = new QHBoxLayout(settings);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(settings);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(16777215, 20));
        widget->setStyleSheet(QString::fromUtf8("background-color:#ffffff;"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEdit);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border:1px solid #cdcdcd;\n"
"}\n"
"QComboBox:hover{\n"
"	border:1px solid #eac222;\n"
"}"));
        comboBox->setEditable(false);

        horizontalLayout->addWidget(comboBox);

        createTable = new QPushButton(widget);
        createTable->setObjectName("createTable");
        sizePolicy.setHeightForWidth(createTable->sizePolicy().hasHeightForWidth());
        createTable->setSizePolicy(sizePolicy);
        createTable->setMaximumSize(QSize(16777215, 16777215));
        createTable->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        createTable->setAutoDefault(false);
        createTable->setFlat(true);

        horizontalLayout->addWidget(createTable);

        deleteTable = new QPushButton(widget);
        deleteTable->setObjectName("deleteTable");
        sizePolicy.setHeightForWidth(deleteTable->sizePolicy().hasHeightForWidth());
        deleteTable->setSizePolicy(sizePolicy);
        deleteTable->setMaximumSize(QSize(16777215, 16777215));
        deleteTable->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        deleteTable->setFlat(true);

        horizontalLayout->addWidget(deleteTable);

        clearTable = new QPushButton(widget);
        clearTable->setObjectName("clearTable");
        sizePolicy.setHeightForWidth(clearTable->sizePolicy().hasHeightForWidth());
        clearTable->setSizePolicy(sizePolicy);
        clearTable->setMaximumSize(QSize(16777215, 16777215));
        clearTable->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        clearTable->setFlat(true);

        horizontalLayout->addWidget(clearTable);

        refreshButton = new QPushButton(widget);
        refreshButton->setObjectName("refreshButton");
        sizePolicy.setHeightForWidth(refreshButton->sizePolicy().hasHeightForWidth());
        refreshButton->setSizePolicy(sizePolicy);
        refreshButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));

        horizontalLayout->addWidget(refreshButton);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addWidget(widget);

        tableView = new QTableView(settings);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setAlternatingRowColors(true);
        tableView->setSortingEnabled(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(settings);

        createTable->setDefault(true);
        deleteTable->setDefault(true);
        clearTable->setDefault(true);


        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QWidget *settings)
    {
        settings->setWindowTitle(QCoreApplication::translate("settings", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("settings", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setPlaceholderText(QCoreApplication::translate("settings", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\215\225\350\257\215\346\210\226\351\207\212\344\271\211", nullptr));
        comboBox->setCurrentText(QString());
        comboBox->setPlaceholderText(QCoreApplication::translate("settings", "\345\210\207\346\215\242\345\215\225\350\257\215\350\241\250", nullptr));
        createTable->setText(QCoreApplication::translate("settings", "\346\226\260\345\273\272\345\215\225\350\257\215\350\241\250", nullptr));
        deleteTable->setText(QCoreApplication::translate("settings", "\345\210\240\351\231\244\345\215\225\350\257\215\350\241\250", nullptr));
        clearTable->setText(QCoreApplication::translate("settings", "\346\270\205\347\251\272\345\215\225\350\257\215\350\241\250", nullptr));
        refreshButton->setText(QCoreApplication::translate("settings", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
