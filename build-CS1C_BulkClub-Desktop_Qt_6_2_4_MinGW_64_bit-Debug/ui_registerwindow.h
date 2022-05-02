/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *password_label;
    QPushButton *information_button;
    QLabel *header_label;
    QLineEdit *password_textbox;
    QComboBox *user_type_combo;
    QLabel *username_label;
    QPushButton *login_button;
    QLineEdit *username_textbox;
    QLabel *user_type_label;
    QLabel *confirm_password_label;
    QLineEdit *confirm_password_textbox;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(600, 400);
        password_label = new QLabel(RegisterWindow);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(130, 130, 101, 31));
        password_label->setStyleSheet(QString::fromUtf8("QLabel#password_label {\n"
"	color: white;\n"
"	font-size: 20px;\n"
"}"));
        password_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        information_button = new QPushButton(RegisterWindow);
        information_button->setObjectName(QString::fromUtf8("information_button"));
        information_button->setGeometry(QRect(250, 310, 201, 31));
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
        header_label = new QLabel(RegisterWindow);
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
        password_textbox = new QLineEdit(RegisterWindow);
        password_textbox->setObjectName(QString::fromUtf8("password_textbox"));
        password_textbox->setGeometry(QRect(240, 130, 211, 31));
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
        user_type_combo = new QComboBox(RegisterWindow);
        user_type_combo->addItem(QString());
        user_type_combo->addItem(QString());
        user_type_combo->addItem(QString());
        user_type_combo->setObjectName(QString::fromUtf8("user_type_combo"));
        user_type_combo->setGeometry(QRect(240, 210, 211, 31));
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
        username_label = new QLabel(RegisterWindow);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(130, 90, 101, 31));
        username_label->setStyleSheet(QString::fromUtf8("QLabel#username_label {\n"
"	font-size: 20px;\n"
"	color: white;\n"
"}"));
        username_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        login_button = new QPushButton(RegisterWindow);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(320, 270, 131, 31));
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
        username_textbox = new QLineEdit(RegisterWindow);
        username_textbox->setObjectName(QString::fromUtf8("username_textbox"));
        username_textbox->setGeometry(QRect(240, 90, 211, 31));
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
        user_type_label = new QLabel(RegisterWindow);
        user_type_label->setObjectName(QString::fromUtf8("user_type_label"));
        user_type_label->setGeometry(QRect(120, 210, 111, 21));
        user_type_label->setStyleSheet(QString::fromUtf8("QLabel#user_type_label {\n"
"	font-size: 18px;\n"
"	color: white;\n"
"}"));
        user_type_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirm_password_label = new QLabel(RegisterWindow);
        confirm_password_label->setObjectName(QString::fromUtf8("confirm_password_label"));
        confirm_password_label->setGeometry(QRect(50, 170, 181, 31));
        confirm_password_label->setStyleSheet(QString::fromUtf8("QLabel#confirm_password_label {\n"
"	color: white;\n"
"	font-size: 20px;\n"
"}"));
        confirm_password_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        confirm_password_textbox = new QLineEdit(RegisterWindow);
        confirm_password_textbox->setObjectName(QString::fromUtf8("confirm_password_textbox"));
        confirm_password_textbox->setGeometry(QRect(240, 170, 211, 31));
        confirm_password_textbox->setFocusPolicy(Qt::ClickFocus);
        confirm_password_textbox->setStyleSheet(QString::fromUtf8("QLineEdit#confirm_password_textbox {\n"
"	color: white;\n"
"	background: black;\n"
"	font-family: arial;\n"
"	font-siz	e: 16px;\n"
"	border:1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QLineEdit#confirm_password_textbox:hover {\n"
"	background: #191b1c;\n"
"	border: 2px solid white;\n"
"}"));
        confirm_password_textbox->setEchoMode(QLineEdit::Password);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        password_label->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        information_button->setText(QCoreApplication::translate("RegisterWindow", "Read Terms and Conditions", nullptr));
        header_label->setText(QCoreApplication::translate("RegisterWindow", "Bulk Club Registration", nullptr));
        password_textbox->setInputMask(QString());
        user_type_combo->setItemText(0, QCoreApplication::translate("RegisterWindow", "None Selected", nullptr));
        user_type_combo->setItemText(1, QCoreApplication::translate("RegisterWindow", "Administrator", nullptr));
        user_type_combo->setItemText(2, QCoreApplication::translate("RegisterWindow", "Store Manager", nullptr));

        username_label->setText(QCoreApplication::translate("RegisterWindow", "Username:", nullptr));
        login_button->setText(QCoreApplication::translate("RegisterWindow", "Register Now", nullptr));
        user_type_label->setText(QCoreApplication::translate("RegisterWindow", "Type of User:", nullptr));
        confirm_password_label->setText(QCoreApplication::translate("RegisterWindow", "Confirm Password:", nullptr));
        confirm_password_textbox->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
