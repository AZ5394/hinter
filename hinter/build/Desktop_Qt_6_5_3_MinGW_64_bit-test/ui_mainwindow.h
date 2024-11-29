/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLabel *word;
    QLabel *paraphrase;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *settingBtn;
    QPushButton *setShowingStateBtn;
    QPushButton *pauseBtn;
    QPushButton *showParaphraseBtn;
    QDoubleSpinBox *interval;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 150);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:#ffffff;"));
        horizontalLayout_2 = new QHBoxLayout(MainWindow);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(MainWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI Light")});
        font.setPointSize(10);
        lineEdit->setFont(font);
        lineEdit->setMouseTracking(true);
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        verticalLayout->addWidget(lineEdit);

        word = new QLabel(MainWindow);
        word->setObjectName("word");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(word->sizePolicy().hasHeightForWidth());
        word->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(17);
        word->setFont(font1);
        word->setStyleSheet(QString::fromUtf8(""));
        word->setScaledContents(false);
        word->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(word);

        paraphrase = new QLabel(MainWindow);
        paraphrase->setObjectName("paraphrase");
        sizePolicy1.setHeightForWidth(paraphrase->sizePolicy().hasHeightForWidth());
        paraphrase->setSizePolicy(sizePolicy1);
        paraphrase->setFont(font1);
        paraphrase->setScaledContents(false);
        paraphrase->setAlignment(Qt::AlignCenter);
        paraphrase->setWordWrap(true);

        verticalLayout->addWidget(paraphrase);


        horizontalLayout->addLayout(verticalLayout);

        widget = new QWidget(MainWindow);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("border-width:1px;\n"
"border-style:solid;\n"
"border-left-color: #dcdcdc;"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        settingBtn = new QPushButton(widget);
        settingBtn->setObjectName("settingBtn");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(settingBtn->sizePolicy().hasHeightForWidth());
        settingBtn->setSizePolicy(sizePolicy2);
        settingBtn->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei UI Light")});
        font2.setPointSize(12);
        settingBtn->setFont(font2);
        settingBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        settingBtn->setAutoDefault(false);
        settingBtn->setFlat(true);

        verticalLayout_3->addWidget(settingBtn);

        setShowingStateBtn = new QPushButton(widget);
        setShowingStateBtn->setObjectName("setShowingStateBtn");
        sizePolicy2.setHeightForWidth(setShowingStateBtn->sizePolicy().hasHeightForWidth());
        setShowingStateBtn->setSizePolicy(sizePolicy2);
        setShowingStateBtn->setMaximumSize(QSize(16777215, 16777215));
        setShowingStateBtn->setFont(font2);
        setShowingStateBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-top:1px solid #cdcdcd;\n"
"	border-bottom:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        setShowingStateBtn->setFlat(true);

        verticalLayout_3->addWidget(setShowingStateBtn);

        pauseBtn = new QPushButton(widget);
        pauseBtn->setObjectName("pauseBtn");
        sizePolicy2.setHeightForWidth(pauseBtn->sizePolicy().hasHeightForWidth());
        pauseBtn->setSizePolicy(sizePolicy2);
        pauseBtn->setMaximumSize(QSize(16777215, 16777215));
        pauseBtn->setFont(font2);
        pauseBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        pauseBtn->setCheckable(false);
        pauseBtn->setChecked(false);
        pauseBtn->setFlat(true);

        verticalLayout_3->addWidget(pauseBtn);

        showParaphraseBtn = new QPushButton(widget);
        showParaphraseBtn->setObjectName("showParaphraseBtn");
        sizePolicy2.setHeightForWidth(showParaphraseBtn->sizePolicy().hasHeightForWidth());
        showParaphraseBtn->setSizePolicy(sizePolicy2);
        showParaphraseBtn->setMaximumSize(QSize(16777215, 16777215));
        showParaphraseBtn->setFont(font2);
        showParaphraseBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-top:1px solid #cdcdcd;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #eac222;\n"
"}\n"
"QPushButton:pressed{\n"
"	border:1px solid #0067c0;\n"
"}"));
        showParaphraseBtn->setCheckable(true);
        showParaphraseBtn->setChecked(true);
        showParaphraseBtn->setFlat(true);

        verticalLayout_3->addWidget(showParaphraseBtn);

        interval = new QDoubleSpinBox(widget);
        interval->setObjectName("interval");
        sizePolicy2.setHeightForWidth(interval->sizePolicy().hasHeightForWidth());
        interval->setSizePolicy(sizePolicy2);
        interval->setMaximumSize(QSize(16777215, 16777215));
        interval->setFont(font2);
        interval->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	border-color:#dcdcdc;\n"
"}\n"
"QDoubleSpinBox:hover{\n"
"	border:1px solid #eac222\n"
"}\n"
"QDoubleSpinBox:clicked{\n"
"	border:none;\n"
"}"));
        interval->setDecimals(1);
        interval->setMinimum(0.100000000000000);
        interval->setMaximum(9999.899999999999636);
        interval->setSingleStep(0.100000000000000);
        interval->setValue(1.000000000000000);

        verticalLayout_3->addWidget(interval);


        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MainWindow);

        settingBtn->setDefault(true);
        setShowingStateBtn->setDefault(true);
        pauseBtn->setDefault(true);
        showParaphraseBtn->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "hinter", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\215\225\350\257\215", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\215\225\350\257\215", nullptr));
        word->setText(QString());
        paraphrase->setText(QString());
        settingBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        setShowingStateBtn->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217", nullptr));
        pauseBtn->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        showParaphraseBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\351\207\212\344\271\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
