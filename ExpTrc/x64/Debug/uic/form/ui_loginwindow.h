/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include "button.h"
#include "textbox.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    Button *loginBtn;
    QLabel *lblLogin;
    Textbox *usernameTxt;
    Textbox *passwordTxt;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(280, 400);
        LoginWindow->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"margin: 30px auto;\n"
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
"\n"
"QPushButton{\n"
"border: 0;\n"
"background-color:  #1F1F1F;\n"
"margin: 30px auto;\n"
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
"QDialog{\n"
"background-color:  #1F1F1F;\n"
"}"));
        loginBtn = new Button(LoginWindow);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(50, 250, 180, 111));
        QFont font;
        font.setPointSize(12);
        loginBtn->setFont(font);
        lblLogin = new QLabel(LoginWindow);
        lblLogin->setObjectName(QString::fromUtf8("lblLogin"));
        lblLogin->setGeometry(QRect(0, 29, 281, 41));
        QFont font1;
        font1.setPointSize(16);
        lblLogin->setFont(font1);
        lblLogin->setAlignment(Qt::AlignCenter);
        usernameTxt = new Textbox(LoginWindow);
        usernameTxt->setObjectName(QString::fromUtf8("usernameTxt"));
        usernameTxt->setGeometry(QRect(0, 60, 281, 111));
        QFont font2;
        font2.setPointSize(14);
        usernameTxt->setFont(font2);
        passwordTxt = new Textbox(LoginWindow);
        passwordTxt->setObjectName(QString::fromUtf8("passwordTxt"));
        passwordTxt->setGeometry(QRect(0, 150, 281, 111));
        passwordTxt->setFont(font2);
        QWidget::setTabOrder(usernameTxt, passwordTxt);
        QWidget::setTabOrder(passwordTxt, loginBtn);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        lblLogin->setText(QCoreApplication::translate("LoginWindow", "LOGIN", nullptr));
        usernameTxt->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        passwordTxt->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
