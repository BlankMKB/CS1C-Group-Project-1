/********************************************************************************
** Form generated from reading UI file 'administratorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORWINDOW_H
#define UI_ADMINISTRATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorWindow
{
public:
    QLabel *header_label;
    QPushButton *logout_button;
    QTabWidget *tabWidget;
    QWidget *InventoryTab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ItemAddButton;
    QPushButton *ItemDeleteButton;
    QPushButton *ItemEditButton;
    QPushButton *ItemFindButton;
    QPushButton *ItemsAllButton;
    QWidget *MembershipsTab;
    QGroupBox *groupBox;

    void setupUi(QDialog *AdministratorWindow)
    {
        if (AdministratorWindow->objectName().isEmpty())
            AdministratorWindow->setObjectName(QString::fromUtf8("AdministratorWindow"));
        AdministratorWindow->resize(800, 600);
        AdministratorWindow->setStyleSheet(QString::fromUtf8("QDialog#AdministratorWindow{\n"
"	background: #5a6166\n"
"}"));
        header_label = new QLabel(AdministratorWindow);
        header_label->setObjectName(QString::fromUtf8("header_label"));
        header_label->setGeometry(QRect(0, 0, 801, 61));
        header_label->setStyleSheet(QString::fromUtf8("QLabel#header_label {\n"
"	font-size: 34px;\n"
"	font-weight: bold;\n"
"	text-decoration: overline underline;\n"
"	color: #3d1a1a;\n"
"}"));
        header_label->setAlignment(Qt::AlignCenter);
        logout_button = new QPushButton(AdministratorWindow);
        logout_button->setObjectName(QString::fromUtf8("logout_button"));
        logout_button->setGeometry(QRect(10, 550, 781, 41));
        logout_button->setStyleSheet(QString::fromUtf8("QPushButton#logout_button{\n"
"	background: gray;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"	border:2px solid #000000;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton#logout_button:hover{\n"
"	background: #b2b9bf;\n"
"}"));
        tabWidget = new QTabWidget(AdministratorWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 100, 251, 411));
        InventoryTab = new QWidget();
        InventoryTab->setObjectName(QString::fromUtf8("InventoryTab"));
        layoutWidget = new QWidget(InventoryTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 201, 301));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ItemAddButton = new QPushButton(layoutWidget);
        ItemAddButton->setObjectName(QString::fromUtf8("ItemAddButton"));

        verticalLayout->addWidget(ItemAddButton);

        ItemDeleteButton = new QPushButton(layoutWidget);
        ItemDeleteButton->setObjectName(QString::fromUtf8("ItemDeleteButton"));

        verticalLayout->addWidget(ItemDeleteButton);

        ItemEditButton = new QPushButton(layoutWidget);
        ItemEditButton->setObjectName(QString::fromUtf8("ItemEditButton"));

        verticalLayout->addWidget(ItemEditButton);

        ItemFindButton = new QPushButton(layoutWidget);
        ItemFindButton->setObjectName(QString::fromUtf8("ItemFindButton"));

        verticalLayout->addWidget(ItemFindButton);

        ItemsAllButton = new QPushButton(layoutWidget);
        ItemsAllButton->setObjectName(QString::fromUtf8("ItemsAllButton"));

        verticalLayout->addWidget(ItemsAllButton);

        tabWidget->addTab(InventoryTab, QString());
        MembershipsTab = new QWidget();
        MembershipsTab->setObjectName(QString::fromUtf8("MembershipsTab"));
        tabWidget->addTab(MembershipsTab, QString());
        groupBox = new QGroupBox(AdministratorWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(290, 100, 491, 411));

        retranslateUi(AdministratorWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdministratorWindow);
    } // setupUi

    void retranslateUi(QDialog *AdministratorWindow)
    {
        AdministratorWindow->setWindowTitle(QCoreApplication::translate("AdministratorWindow", "Administrator Window", nullptr));
        header_label->setText(QCoreApplication::translate("AdministratorWindow", "Administrator Access has been Granted!", nullptr));
        logout_button->setText(QCoreApplication::translate("AdministratorWindow", "Logout Now", nullptr));
        ItemAddButton->setText(QCoreApplication::translate("AdministratorWindow", "Add Item", nullptr));
        ItemDeleteButton->setText(QCoreApplication::translate("AdministratorWindow", "Delete Item", nullptr));
        ItemEditButton->setText(QCoreApplication::translate("AdministratorWindow", "Edit Item", nullptr));
        ItemFindButton->setText(QCoreApplication::translate("AdministratorWindow", "Lookup Item", nullptr));
        ItemsAllButton->setText(QCoreApplication::translate("AdministratorWindow", "All Items", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(InventoryTab), QCoreApplication::translate("AdministratorWindow", "Edit Inventory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MembershipsTab), QCoreApplication::translate("AdministratorWindow", "Memberships", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdministratorWindow", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorWindow: public Ui_AdministratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORWINDOW_H
