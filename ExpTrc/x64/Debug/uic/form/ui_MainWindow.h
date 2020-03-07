/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "button.h"
#include "checkbox.h"
#include "combobox.h"
#include "listbox.h"
#include "plaintext.h"
#include "textbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChange_directory;
    QAction *actionEdit_Expense_Taking;
    QAction *actionEdit_Users;
    QAction *actionSearch_Item;
    QAction *actionEnglish;
    QAction *actionGerman;
    QAction *actionChange_Theme;
    QWidget *centralwidget;
    Listbox *lstbox;
    Listbox *lstboxMonth;
    Button *deleteBtn;
    Button *dupBtn;
    Button *clearBtn;
    Button *moreInfoBtn;
    Button *monthGraphBtn;
    Button *yearGraphBtn;
    Listbox *lstboxTakings;
    Listbox *lstboxTakingsMonth;
    QLabel *lblInfoMonthly;
    QLabel *lblInfoOneTime;
    QLabel *lblInfoOneTimeTak;
    QLabel *lblInfoMonthlyTak;
    Textbox *expNameTxt;
    Textbox *expPriceTxt;
    Combobox *comboboxCur;
    PlainText *expInfoTxt;
    Checkbox *chbOneTime;
    Checkbox *chbOneTimeTakings;
    Checkbox *chbMonthly;
    Checkbox *chbMonthlyTakings;
    Combobox *comboboxExpCat;
    Combobox *comboboxTakCat;
    Combobox *comboboxCatInpt;
    QLabel *lblInfoExpCat;
    QLabel *lblInfoTakCat;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutTotalTxt;
    QLabel *lblTotalIncome;
    QLabel *lblTotalExpense;
    QLabel *lblRemainingBudget;
    QLabel *lblRemainingBank;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layoutTotalValues;
    QLabel *lblTotalIncomeVal;
    QLabel *lblTotalExpVal;
    QLabel *lblRemainingVal;
    QLabel *lblRemainingBankVal;
    Button *addBtn;
    QSpinBox *expMultiTxt;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblBrutoBudgetTxt;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblBudgetValue;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuLanguage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 680);
        MainWindow->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"QLineEdit::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QListWidget{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"\n"
"QListWidget::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QPlainTextEdit{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"QPlainTextEdit::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QMenuBar{\n"
"background-color:  #1F1F1F;\n"
"color: white;\n"
"}\n"
"\n"
"QComboBox{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
""
                        "}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QComboBox::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QSpinBox{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"QSpinBox::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QCheckBox{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"QCheckBox::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QPushButton{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"border: 2px solid #3498db;\n"
"padding: 14px 10px;\n"
"outline: none;\n"
"color: white;\n"
"border-radius: 24px;\n"
"}\n"
"\n"
"QPushButton::pressed{\n"
"background-color: rgb(100, 100, 100);\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"border-color:  #2ecc71;\n"
"}\n"
"\n"
"QLabel{\n"
"color: white;\n"
"}\n"
"\n"
"QMainWindow{\n"
"background-color:  #1F1F1F;\n"
"}\n"
"\n"
""
                        "\n"
"QComboBox::drop-down {\n"
"border-width: 0px;\n"
"}\n"
"\n"
" \n"
"QComboBox::down-arrow {\n"
"image: url(noimg); border-width: 0px;\n"
"}\n"
""));
        actionChange_directory = new QAction(MainWindow);
        actionChange_directory->setObjectName(QString::fromUtf8("actionChange_directory"));
        actionEdit_Expense_Taking = new QAction(MainWindow);
        actionEdit_Expense_Taking->setObjectName(QString::fromUtf8("actionEdit_Expense_Taking"));
        actionEdit_Users = new QAction(MainWindow);
        actionEdit_Users->setObjectName(QString::fromUtf8("actionEdit_Users"));
        actionSearch_Item = new QAction(MainWindow);
        actionSearch_Item->setObjectName(QString::fromUtf8("actionSearch_Item"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionGerman = new QAction(MainWindow);
        actionGerman->setObjectName(QString::fromUtf8("actionGerman"));
        actionChange_Theme = new QAction(MainWindow);
        actionChange_Theme->setObjectName(QString::fromUtf8("actionChange_Theme"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lstbox = new Listbox(centralwidget);
        lstbox->setObjectName(QString::fromUtf8("lstbox"));
        lstbox->setGeometry(QRect(10, 20, 180, 340));
        QFont font;
        font.setPointSize(13);
        lstbox->setFont(font);
        lstbox->setStyleSheet(QString::fromUtf8(""));
        lstbox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstbox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstboxMonth = new Listbox(centralwidget);
        lstboxMonth->setObjectName(QString::fromUtf8("lstboxMonth"));
        lstboxMonth->setGeometry(QRect(10, 400, 180, 230));
        lstboxMonth->setFont(font);
        lstboxMonth->setStyleSheet(QString::fromUtf8(""));
        lstboxMonth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstboxMonth->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        deleteBtn = new Button(centralwidget);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(210, 130, 100, 50));
        dupBtn = new Button(centralwidget);
        dupBtn->setObjectName(QString::fromUtf8("dupBtn"));
        dupBtn->setGeometry(QRect(210, 210, 100, 50));
        clearBtn = new Button(centralwidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        clearBtn->setGeometry(QRect(210, 290, 100, 50));
        moreInfoBtn = new Button(centralwidget);
        moreInfoBtn->setObjectName(QString::fromUtf8("moreInfoBtn"));
        moreInfoBtn->setGeometry(QRect(210, 370, 100, 50));
        monthGraphBtn = new Button(centralwidget);
        monthGraphBtn->setObjectName(QString::fromUtf8("monthGraphBtn"));
        monthGraphBtn->setGeometry(QRect(210, 530, 100, 50));
        yearGraphBtn = new Button(centralwidget);
        yearGraphBtn->setObjectName(QString::fromUtf8("yearGraphBtn"));
        yearGraphBtn->setGeometry(QRect(210, 450, 100, 50));
        lstboxTakings = new Listbox(centralwidget);
        lstboxTakings->setObjectName(QString::fromUtf8("lstboxTakings"));
        lstboxTakings->setGeometry(QRect(1010, 20, 180, 340));
        lstboxTakings->setFont(font);
        lstboxTakings->setStyleSheet(QString::fromUtf8(""));
        lstboxTakings->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstboxTakings->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstboxTakingsMonth = new Listbox(centralwidget);
        lstboxTakingsMonth->setObjectName(QString::fromUtf8("lstboxTakingsMonth"));
        lstboxTakingsMonth->setGeometry(QRect(1010, 400, 180, 230));
        lstboxTakingsMonth->setFont(font);
        lstboxTakingsMonth->setStyleSheet(QString::fromUtf8(""));
        lstboxTakingsMonth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lstboxTakingsMonth->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lblInfoMonthly = new QLabel(centralwidget);
        lblInfoMonthly->setObjectName(QString::fromUtf8("lblInfoMonthly"));
        lblInfoMonthly->setGeometry(QRect(20, 380, 190, 20));
        lblInfoMonthly->setFont(font);
        lblInfoOneTime = new QLabel(centralwidget);
        lblInfoOneTime->setObjectName(QString::fromUtf8("lblInfoOneTime"));
        lblInfoOneTime->setGeometry(QRect(20, 0, 180, 20));
        lblInfoOneTime->setFont(font);
        lblInfoOneTimeTak = new QLabel(centralwidget);
        lblInfoOneTimeTak->setObjectName(QString::fromUtf8("lblInfoOneTimeTak"));
        lblInfoOneTimeTak->setGeometry(QRect(1010, 0, 180, 20));
        lblInfoOneTimeTak->setFont(font);
        lblInfoMonthlyTak = new QLabel(centralwidget);
        lblInfoMonthlyTak->setObjectName(QString::fromUtf8("lblInfoMonthlyTak"));
        lblInfoMonthlyTak->setGeometry(QRect(1009, 380, 190, 20));
        lblInfoMonthlyTak->setFont(font);
        expNameTxt = new Textbox(centralwidget);
        expNameTxt->setObjectName(QString::fromUtf8("expNameTxt"));
        expNameTxt->setGeometry(QRect(340, 50, 230, 50));
        QFont font1;
        font1.setPointSize(16);
        expNameTxt->setFont(font1);
        expNameTxt->setStyleSheet(QString::fromUtf8(""));
        expNameTxt->setAlignment(Qt::AlignCenter);
        expPriceTxt = new Textbox(centralwidget);
        expPriceTxt->setObjectName(QString::fromUtf8("expPriceTxt"));
        expPriceTxt->setGeometry(QRect(620, 50, 230, 50));
        expPriceTxt->setFont(font1);
        expPriceTxt->setStyleSheet(QString::fromUtf8(""));
        expPriceTxt->setAlignment(Qt::AlignCenter);
        comboboxCur = new Combobox(centralwidget);
        comboboxCur->addItem(QString());
        comboboxCur->addItem(QString());
        comboboxCur->setObjectName(QString::fromUtf8("comboboxCur"));
        comboboxCur->setGeometry(QRect(890, 50, 77, 48));
        comboboxCur->setStyleSheet(QString::fromUtf8("QListView{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"outline: none;\n"
"color: white;\n"
"}\n"
""));
        comboboxCur->setMaxVisibleItems(2);
        comboboxCur->setMaxCount(2);
        comboboxCur->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        expInfoTxt = new PlainText(centralwidget);
        expInfoTxt->setObjectName(QString::fromUtf8("expInfoTxt"));
        expInfoTxt->setGeometry(QRect(340, 240, 600, 120));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(expInfoTxt->sizePolicy().hasHeightForWidth());
        expInfoTxt->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        expInfoTxt->setFont(font2);
        expInfoTxt->setStyleSheet(QString::fromUtf8(""));
        chbOneTime = new Checkbox(centralwidget);
        chbOneTime->setObjectName(QString::fromUtf8("chbOneTime"));
        chbOneTime->setGeometry(QRect(580, 120, 160, 45));
        chbOneTime->setStyleSheet(QString::fromUtf8(""));
        chbOneTimeTakings = new Checkbox(centralwidget);
        chbOneTimeTakings->setObjectName(QString::fromUtf8("chbOneTimeTakings"));
        chbOneTimeTakings->setGeometry(QRect(760, 120, 160, 45));
        chbMonthly = new Checkbox(centralwidget);
        chbMonthly->setObjectName(QString::fromUtf8("chbMonthly"));
        chbMonthly->setGeometry(QRect(580, 180, 160, 45));
        chbMonthlyTakings = new Checkbox(centralwidget);
        chbMonthlyTakings->setObjectName(QString::fromUtf8("chbMonthlyTakings"));
        chbMonthlyTakings->setGeometry(QRect(760, 180, 160, 45));
        comboboxExpCat = new Combobox(centralwidget);
        comboboxExpCat->setObjectName(QString::fromUtf8("comboboxExpCat"));
        comboboxExpCat->setGeometry(QRect(350, 400, 170, 50));
        comboboxExpCat->setStyleSheet(QString::fromUtf8("QListView{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"outline: none;\n"
"color: white;\n"
"}"));
        comboboxTakCat = new Combobox(centralwidget);
        comboboxTakCat->setObjectName(QString::fromUtf8("comboboxTakCat"));
        comboboxTakCat->setGeometry(QRect(730, 400, 170, 50));
        comboboxTakCat->setStyleSheet(QString::fromUtf8("QListView{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"outline: none;\n"
"color: white;\n"
"}\n"
""));
        comboboxCatInpt = new Combobox(centralwidget);
        comboboxCatInpt->setObjectName(QString::fromUtf8("comboboxCatInpt"));
        comboboxCatInpt->setGeometry(QRect(340, 150, 100, 50));
        comboboxCatInpt->setStyleSheet(QString::fromUtf8("QListView{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"outline: none;\n"
"color: white;\n"
"}"));
        comboboxCatInpt->setEditable(true);
        lblInfoExpCat = new QLabel(centralwidget);
        lblInfoExpCat->setObjectName(QString::fromUtf8("lblInfoExpCat"));
        lblInfoExpCat->setGeometry(QRect(350, 380, 190, 20));
        lblInfoTakCat = new QLabel(centralwidget);
        lblInfoTakCat->setObjectName(QString::fromUtf8("lblInfoTakCat"));
        lblInfoTakCat->setGeometry(QRect(730, 380, 180, 20));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(350, 480, 331, 152));
        layoutTotalTxt = new QVBoxLayout(verticalLayoutWidget);
        layoutTotalTxt->setObjectName(QString::fromUtf8("layoutTotalTxt"));
        layoutTotalTxt->setContentsMargins(0, 0, 0, 0);
        lblTotalIncome = new QLabel(verticalLayoutWidget);
        lblTotalIncome->setObjectName(QString::fromUtf8("lblTotalIncome"));
        QFont font3;
        font3.setPointSize(15);
        lblTotalIncome->setFont(font3);

        layoutTotalTxt->addWidget(lblTotalIncome);

        lblTotalExpense = new QLabel(verticalLayoutWidget);
        lblTotalExpense->setObjectName(QString::fromUtf8("lblTotalExpense"));
        lblTotalExpense->setFont(font3);

        layoutTotalTxt->addWidget(lblTotalExpense);

        lblRemainingBudget = new QLabel(verticalLayoutWidget);
        lblRemainingBudget->setObjectName(QString::fromUtf8("lblRemainingBudget"));
        lblRemainingBudget->setFont(font3);

        layoutTotalTxt->addWidget(lblRemainingBudget);

        lblRemainingBank = new QLabel(verticalLayoutWidget);
        lblRemainingBank->setObjectName(QString::fromUtf8("lblRemainingBank"));
        lblRemainingBank->setFont(font3);

        layoutTotalTxt->addWidget(lblRemainingBank);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(690, 480, 201, 152));
        layoutTotalValues = new QVBoxLayout(verticalLayoutWidget_2);
        layoutTotalValues->setObjectName(QString::fromUtf8("layoutTotalValues"));
        layoutTotalValues->setContentsMargins(0, 0, 0, 0);
        lblTotalIncomeVal = new QLabel(verticalLayoutWidget_2);
        lblTotalIncomeVal->setObjectName(QString::fromUtf8("lblTotalIncomeVal"));
        lblTotalIncomeVal->setFont(font3);

        layoutTotalValues->addWidget(lblTotalIncomeVal);

        lblTotalExpVal = new QLabel(verticalLayoutWidget_2);
        lblTotalExpVal->setObjectName(QString::fromUtf8("lblTotalExpVal"));
        lblTotalExpVal->setFont(font3);

        layoutTotalValues->addWidget(lblTotalExpVal);

        lblRemainingVal = new QLabel(verticalLayoutWidget_2);
        lblRemainingVal->setObjectName(QString::fromUtf8("lblRemainingVal"));
        lblRemainingVal->setFont(font3);

        layoutTotalValues->addWidget(lblRemainingVal);

        lblRemainingBankVal = new QLabel(verticalLayoutWidget_2);
        lblRemainingBankVal->setObjectName(QString::fromUtf8("lblRemainingBankVal"));
        lblRemainingBankVal->setFont(font3);

        layoutTotalValues->addWidget(lblRemainingBankVal);

        addBtn = new Button(centralwidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(210, 50, 100, 50));
        expMultiTxt = new QSpinBox(centralwidget);
        expMultiTxt->setObjectName(QString::fromUtf8("expMultiTxt"));
        expMultiTxt->setGeometry(QRect(470, 150, 100, 50));
        expMultiTxt->setStyleSheet(QString::fromUtf8("QListView{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"outline: none;\n"
"color: white;\n"
"}"));
        expMultiTxt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        expMultiTxt->setMinimum(1);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(340, 0, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblBrutoBudgetTxt = new QLabel(horizontalLayoutWidget);
        lblBrutoBudgetTxt->setObjectName(QString::fromUtf8("lblBrutoBudgetTxt"));
        lblBrutoBudgetTxt->setFont(font3);
        lblBrutoBudgetTxt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblBrutoBudgetTxt);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(690, 0, 201, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblBudgetValue = new QLabel(horizontalLayoutWidget_2);
        lblBudgetValue->setObjectName(QString::fromUtf8("lblBudgetValue"));
        lblBudgetValue->setFont(font3);

        horizontalLayout_2->addWidget(lblBudgetValue);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionChange_directory);
        menuEdit->addAction(actionEdit_Expense_Taking);
        menuEdit->addAction(actionEdit_Users);
        menuView->addAction(actionSearch_Item);
        menuView->addSeparator();
        menuView->addAction(actionChange_Theme);
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionGerman);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionChange_directory->setText(QApplication::translate("MainWindow", "Change directory...", nullptr));
        actionEdit_Expense_Taking->setText(QApplication::translate("MainWindow", "Edit Expense/Taking...", nullptr));
        actionEdit_Users->setText(QApplication::translate("MainWindow", "Edit Users...", nullptr));
        actionSearch_Item->setText(QApplication::translate("MainWindow", "Search Item", nullptr));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", nullptr));
        actionGerman->setText(QApplication::translate("MainWindow", "German", nullptr));
        actionChange_Theme->setText(QApplication::translate("MainWindow", "Change Theme", nullptr));
        deleteBtn->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        dupBtn->setText(QApplication::translate("MainWindow", "Dublicate", nullptr));
        clearBtn->setText(QApplication::translate("MainWindow", "Clear List", nullptr));
        moreInfoBtn->setText(QApplication::translate("MainWindow", "More Info", nullptr));
        monthGraphBtn->setText(QApplication::translate("MainWindow", "Month-Graph", nullptr));
        yearGraphBtn->setText(QApplication::translate("MainWindow", "Year-Graph", nullptr));
        lblInfoMonthly->setText(QApplication::translate("MainWindow", "Monthly Expenses", nullptr));
        lblInfoOneTime->setText(QApplication::translate("MainWindow", "One-Time Expenses", nullptr));
        lblInfoOneTimeTak->setText(QApplication::translate("MainWindow", "One-Time Takings", nullptr));
        lblInfoMonthlyTak->setText(QApplication::translate("MainWindow", "Monthly Income Sources", nullptr));
        expNameTxt->setPlaceholderText(QApplication::translate("MainWindow", "Name", nullptr));
        expPriceTxt->setPlaceholderText(QApplication::translate("MainWindow", "Price", nullptr));
        comboboxCur->setItemText(0, QApplication::translate("MainWindow", "Dollar $", nullptr));
        comboboxCur->setItemText(1, QApplication::translate("MainWindow", "Euro \342\202\254", nullptr));

        expInfoTxt->setPlaceholderText(QApplication::translate("MainWindow", "You can write some info about your expense here...", nullptr));
        chbOneTime->setText(QApplication::translate("MainWindow", "One-Time Expenses", nullptr));
        chbOneTimeTakings->setText(QApplication::translate("MainWindow", "One-Time Takings", nullptr));
        chbMonthly->setText(QApplication::translate("MainWindow", "Monthly Expenses", nullptr));
        chbMonthlyTakings->setText(QApplication::translate("MainWindow", "Monthly Income Sources", nullptr));
        lblInfoExpCat->setText(QApplication::translate("MainWindow", "Select Expense Category", nullptr));
        lblInfoTakCat->setText(QApplication::translate("MainWindow", "Select Takings Category", nullptr));
        lblTotalIncome->setText(QApplication::translate("MainWindow", "Your total income: ", nullptr));
        lblTotalExpense->setText(QApplication::translate("MainWindow", "Your total expenses: ", nullptr));
        lblRemainingBudget->setText(QApplication::translate("MainWindow", "Your remaining budget: ", nullptr));
        lblRemainingBank->setText(QApplication::translate("MainWindow", "Your total bank balance: ", nullptr));
        lblTotalIncomeVal->setText(QString());
        lblTotalExpVal->setText(QString());
        lblRemainingVal->setText(QString());
        lblRemainingBankVal->setText(QString());
        addBtn->setText(QApplication::translate("MainWindow", "Add", nullptr));
        lblBrutoBudgetTxt->setText(QApplication::translate("MainWindow", "Your budget: ", nullptr));
        lblBudgetValue->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
