/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *header_label;
    QLabel *access_date;
    QPushButton *information_button;
    QLabel *username_label;
    QLineEdit *password_textbox;
    QLabel *password_label;
    QLabel *user_type_label;
    QPushButton *login_button;
    QLineEdit *username_textbox;
    QComboBox *user_type_combo;
    QDateTimeEdit *date_edit;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(600, 400);
        header_label = new QLabel(LoginWindow);
        header_label->setObjectName(QString::fromUtf8("header_label"));
        header_label->setGeometry(QRect(0, 10, 601, 61));
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        header_label->setFont(font);
        header_label->setStyleSheet(QString::fromUtf8("QLabel#header_label {\n"
"	font-family: Arial Narrow;\n"
"	color: black;\n"
"	font-weight: bold;\n"
"}"));
        header_label->setAlignment(Qt::AlignCenter);
        access_date = new QLabel(LoginWindow);
        access_date->setObjectName(QString::fromUtf8("access_date"));
        access_date->setGeometry(QRect(110, 180, 111, 31));
        QFont font1;
        access_date->setFont(font1);
        access_date->setStyleSheet(QString::fromUtf8("QLabel#access_date{\n"
"	font-size: 18px;\n"
"	color: white;\n"
"}"));
        access_date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        information_button = new QPushButton(LoginWindow);
        information_button->setObjectName(QString::fromUtf8("information_button"));
        information_button->setGeometry(QRect(240, 320, 201, 31));
        information_button->setFocusPolicy(Qt::ClickFocus);
        information_button->setStyleSheet(QString::fromUtf8("QPushButton#information_button{\n"
"	background: gray;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"	border:2px solid #000000;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton#information_button:hover{\n"
"	background: #b2b9bf;\n"
"}"));
        username_label = new QLabel(LoginWindow);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(120, 100, 101, 31));
        username_label->setStyleSheet(QString::fromUtf8("QLabel#username_label {\n"
"	font-size: 20px;\n"
"	color: white;\n"
"}"));
        username_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        password_textbox = new QLineEdit(LoginWindow);
        password_textbox->setObjectName(QString::fromUtf8("password_textbox"));
        password_textbox->setGeometry(QRect(230, 140, 211, 31));
        password_textbox->setFocusPolicy(Qt::ClickFocus);
        password_textbox->setStyleSheet(QString::fromUtf8("QLineEdit#password_textbox {\n"
"	color: white;\n"
"	background: black;\n"
"	font-family: arial;\n"
"	font-siz	e: 16px;\n"
"	border:1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QLineEdit#password_textbox:hover {\n"
"	background: #191b1c;\n"
"	border: 2px solid white;\n"
"}"));
        password_textbox->setEchoMode(QLineEdit::Password);
        password_label = new QLabel(LoginWindow);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(120, 140, 101, 31));
        password_label->setStyleSheet(QString::fromUtf8("QLabel#password_label {\n"
"	color: white;\n"
"	font-size: 20px;\n"
"}"));
        password_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        user_type_label = new QLabel(LoginWindow);
        user_type_label->setObjectName(QString::fromUtf8("user_type_label"));
        user_type_label->setGeometry(QRect(110, 220, 111, 21));
        user_type_label->setStyleSheet(QString::fromUtf8("QLabel#user_type_label {\n"
"	font-size: 18px;\n"
"	color: white;\n"
"}"));
        user_type_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        login_button = new QPushButton(LoginWindow);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(310, 280, 131, 31));
        login_button->setFocusPolicy(Qt::ClickFocus);
        login_button->setStyleSheet(QString::fromUtf8("QPushButton#login_button{\n"
"	background: gray;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"	border:2px solid #000000;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton#login_button:hover{\n"
"	background: #b2b9bf;\n"
"}"));
        username_textbox = new QLineEdit(LoginWindow);
        username_textbox->setObjectName(QString::fromUtf8("username_textbox"));
        username_textbox->setGeometry(QRect(230, 100, 211, 31));
        username_textbox->setFocusPolicy(Qt::ClickFocus);
        username_textbox->setStyleSheet(QString::fromUtf8("QLineEdit#username_textbox {\n"
"	color: white;\n"
"	background: black;\n"
"	font-family: arial;\n"
"	font-siz	e: 16px;\n"
"	border:1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QLineEdit#username_textbox:hover {\n"
"	background: #191b1c;\n"
"	border: 2px solid white;\n"
"}"));
        user_type_combo = new QComboBox(LoginWindow);
        user_type_combo->addItem(QString());
        user_type_combo->addItem(QString());
        user_type_combo->addItem(QString());
        user_type_combo->setObjectName(QString::fromUtf8("user_type_combo"));
        user_type_combo->setGeometry(QRect(230, 220, 211, 31));
        user_type_combo->setFocusPolicy(Qt::ClickFocus);
        user_type_combo->setStyleSheet(QString::fromUtf8("QComboBox#user_type_combo{\n"
"	color: white;\n"
"	font-family: arial;\n"
"	background: pale;\n"
"	border:1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QComboBox#user_type_combo:hover {\n"
"	background: #191b1c;\n"
"	border: 2px solid white;\n"
"}"));
        date_edit = new QDateTimeEdit(LoginWindow);
        date_edit->setObjectName(QString::fromUtf8("date_edit"));
        date_edit->setGeometry(QRect(230, 180, 211, 31));
        date_edit->setFocusPolicy(Qt::ClickFocus);
        date_edit->setStyleSheet(QString::fromUtf8("QDateTimeEdit#date_edit{\n"
"	color: white;\n"
"	background: black;\n"
"	font-family: arial;\n"
"}\n"
"\n"
"QDateTimeEdit#date_edit:hover{\n"
"	background: #191b1c;\n"
"}\n"
""));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        header_label->setText(QCoreApplication::translate("LoginWindow", "Bulk Club Login", nullptr));
        access_date->setText(QCoreApplication::translate("LoginWindow", "Access Date:", nullptr));
        information_button->setText(QCoreApplication::translate("LoginWindow", "Read Terms and Conditions", nullptr));
        username_label->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        password_textbox->setInputMask(QString());
        password_label->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        user_type_label->setText(QCoreApplication::translate("LoginWindow", "Type of User:", nullptr));
        login_button->setText(QCoreApplication::translate("LoginWindow", "Login Now", nullptr));
        user_type_combo->setItemText(0, QCoreApplication::translate("LoginWindow", "None Selected", nullptr));
        user_type_combo->setItemText(1, QCoreApplication::translate("LoginWindow", "Administrator", nullptr));
        user_type_combo->setItemText(2, QCoreApplication::translate("LoginWindow", "Store Manager", nullptr));

    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
