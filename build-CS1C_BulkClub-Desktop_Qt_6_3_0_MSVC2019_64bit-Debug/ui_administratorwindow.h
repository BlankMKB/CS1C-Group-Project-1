/********************************************************************************
** Form generated from reading UI file 'administratorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORWINDOW_H
#define UI_ADMINISTRATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QTabWidget *tabWidget_3;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *itemname_text;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *itemquantity_text;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *itemprice_text;
    QPushButton *Add_Item_Button;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLineEdit *delete_item_text;
    QPushButton *Delete_Item_Button;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QComboBox *Item_Select_CB;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *Edit_Itemname_text;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLineEdit *Edit_Itemquantity_text;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *Edit_Itemprice_text;
    QPushButton *Item_Edit_Button;
    QWidget *tab_4;
    QListWidget *itemlist;
    QWidget *MembershipsTab;
    QTabWidget *tabWidget_2;
    QWidget *Add_Member;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_text;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *id_text;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *type_cb;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *month_cb;
    QLabel *label_5;
    QComboBox *day_cb;
    QLabel *label_6;
    QComboBox *year_cb;
    QPushButton *Add_Button;
    QWidget *Delete_Member;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *delete_id_text;
    QPushButton *Delete_Button;

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
        tabWidget->setGeometry(QRect(10, 80, 601, 451));
        InventoryTab = new QWidget();
        InventoryTab->setObjectName(QString::fromUtf8("InventoryTab"));
        tabWidget_3 = new QTabWidget(InventoryTab);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(40, 20, 411, 281));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 341, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        itemname_text = new QLineEdit(layoutWidget);
        itemname_text->setObjectName(QString::fromUtf8("itemname_text"));

        horizontalLayout_6->addWidget(itemname_text);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        itemquantity_text = new QLineEdit(layoutWidget);
        itemquantity_text->setObjectName(QString::fromUtf8("itemquantity_text"));

        horizontalLayout_7->addWidget(itemquantity_text);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        itemprice_text = new QLineEdit(layoutWidget);
        itemprice_text->setObjectName(QString::fromUtf8("itemprice_text"));

        horizontalLayout_8->addWidget(itemprice_text);


        verticalLayout->addLayout(horizontalLayout_8);

        Add_Item_Button = new QPushButton(layoutWidget);
        Add_Item_Button->setObjectName(QString::fromUtf8("Add_Item_Button"));

        verticalLayout->addWidget(Add_Item_Button);

        tabWidget_3->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 341, 151));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_9->addWidget(label_11);

        delete_item_text = new QLineEdit(layoutWidget1);
        delete_item_text->setObjectName(QString::fromUtf8("delete_item_text"));

        horizontalLayout_9->addWidget(delete_item_text);


        verticalLayout_4->addLayout(horizontalLayout_9);

        Delete_Item_Button = new QPushButton(layoutWidget1);
        Delete_Item_Button->setObjectName(QString::fromUtf8("Delete_Item_Button"));

        verticalLayout_4->addWidget(Delete_Item_Button);

        tabWidget_3->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_10->addWidget(label_12);

        Item_Select_CB = new QComboBox(tab_3);
        Item_Select_CB->setObjectName(QString::fromUtf8("Item_Select_CB"));

        horizontalLayout_10->addWidget(Item_Select_CB);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_11->addWidget(label_13);

        Edit_Itemname_text = new QLineEdit(tab_3);
        Edit_Itemname_text->setObjectName(QString::fromUtf8("Edit_Itemname_text"));

        horizontalLayout_11->addWidget(Edit_Itemname_text);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_12->addWidget(label_14);

        Edit_Itemquantity_text = new QLineEdit(tab_3);
        Edit_Itemquantity_text->setObjectName(QString::fromUtf8("Edit_Itemquantity_text"));

        horizontalLayout_12->addWidget(Edit_Itemquantity_text);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        Edit_Itemprice_text = new QLineEdit(tab_3);
        Edit_Itemprice_text->setObjectName(QString::fromUtf8("Edit_Itemprice_text"));

        horizontalLayout_13->addWidget(Edit_Itemprice_text);


        verticalLayout_5->addLayout(horizontalLayout_13);

        Item_Edit_Button = new QPushButton(tab_3);
        Item_Edit_Button->setObjectName(QString::fromUtf8("Item_Edit_Button"));

        verticalLayout_5->addWidget(Item_Edit_Button);

        tabWidget_3->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        itemlist = new QListWidget(tab_4);
        itemlist->setObjectName(QString::fromUtf8("itemlist"));
        itemlist->setGeometry(QRect(20, 10, 371, 221));
        tabWidget_3->addTab(tab_4, QString());
        tabWidget->addTab(InventoryTab, QString());
        MembershipsTab = new QWidget();
        MembershipsTab->setObjectName(QString::fromUtf8("MembershipsTab"));
        tabWidget_2 = new QTabWidget(MembershipsTab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(40, 19, 391, 281));
        Add_Member = new QWidget();
        Add_Member->setObjectName(QString::fromUtf8("Add_Member"));
        verticalLayout_2 = new QVBoxLayout(Add_Member);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Add_Member);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        name_text = new QLineEdit(Add_Member);
        name_text->setObjectName(QString::fromUtf8("name_text"));

        horizontalLayout->addWidget(name_text);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Add_Member);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        id_text = new QLineEdit(Add_Member);
        id_text->setObjectName(QString::fromUtf8("id_text"));

        horizontalLayout_2->addWidget(id_text);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Add_Member);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        type_cb = new QComboBox(Add_Member);
        type_cb->addItem(QString());
        type_cb->addItem(QString());
        type_cb->setObjectName(QString::fromUtf8("type_cb"));

        horizontalLayout_3->addWidget(type_cb);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Add_Member);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        month_cb = new QComboBox(Add_Member);
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->addItem(QString());
        month_cb->setObjectName(QString::fromUtf8("month_cb"));

        horizontalLayout_4->addWidget(month_cb);

        label_5 = new QLabel(Add_Member);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        day_cb = new QComboBox(Add_Member);
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->addItem(QString());
        day_cb->setObjectName(QString::fromUtf8("day_cb"));

        horizontalLayout_4->addWidget(day_cb);

        label_6 = new QLabel(Add_Member);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        year_cb = new QComboBox(Add_Member);
        year_cb->addItem(QString());
        year_cb->addItem(QString());
        year_cb->setObjectName(QString::fromUtf8("year_cb"));

        horizontalLayout_4->addWidget(year_cb);


        verticalLayout_2->addLayout(horizontalLayout_4);

        Add_Button = new QPushButton(Add_Member);
        Add_Button->setObjectName(QString::fromUtf8("Add_Button"));

        verticalLayout_2->addWidget(Add_Button);

        tabWidget_2->addTab(Add_Member, QString());
        Delete_Member = new QWidget();
        Delete_Member->setObjectName(QString::fromUtf8("Delete_Member"));
        layoutWidget2 = new QWidget(Delete_Member);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 40, 371, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        delete_id_text = new QLineEdit(layoutWidget2);
        delete_id_text->setObjectName(QString::fromUtf8("delete_id_text"));

        horizontalLayout_5->addWidget(delete_id_text);


        verticalLayout_3->addLayout(horizontalLayout_5);

        Delete_Button = new QPushButton(layoutWidget2);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));

        verticalLayout_3->addWidget(Delete_Button);

        tabWidget_2->addTab(Delete_Member, QString());
        tabWidget->addTab(MembershipsTab, QString());

        retranslateUi(AdministratorWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdministratorWindow);
    } // setupUi

    void retranslateUi(QDialog *AdministratorWindow)
    {
        AdministratorWindow->setWindowTitle(QCoreApplication::translate("AdministratorWindow", "Administrator Window", nullptr));
        header_label->setText(QCoreApplication::translate("AdministratorWindow", "Administrator Access has been Granted!", nullptr));
        logout_button->setText(QCoreApplication::translate("AdministratorWindow", "Logout Now", nullptr));
        label_8->setText(QCoreApplication::translate("AdministratorWindow", "Item Name", nullptr));
        label_9->setText(QCoreApplication::translate("AdministratorWindow", "Item Quantity", nullptr));
        label_10->setText(QCoreApplication::translate("AdministratorWindow", "Item Price", nullptr));
        Add_Item_Button->setText(QCoreApplication::translate("AdministratorWindow", "ADD ITEM", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab), QCoreApplication::translate("AdministratorWindow", "Add Item", nullptr));
        label_11->setText(QCoreApplication::translate("AdministratorWindow", "Item Name", nullptr));
        Delete_Item_Button->setText(QCoreApplication::translate("AdministratorWindow", "DELETE ITEM", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QCoreApplication::translate("AdministratorWindow", "Delete Item", nullptr));
        label_12->setText(QCoreApplication::translate("AdministratorWindow", "Item", nullptr));
        label_13->setText(QCoreApplication::translate("AdministratorWindow", "Item Name", nullptr));
        label_14->setText(QCoreApplication::translate("AdministratorWindow", "Item Quantity", nullptr));
        label_15->setText(QCoreApplication::translate("AdministratorWindow", "Item Price", nullptr));
        Item_Edit_Button->setText(QCoreApplication::translate("AdministratorWindow", "Edit", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QCoreApplication::translate("AdministratorWindow", "Edit Item", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_4), QCoreApplication::translate("AdministratorWindow", "Look Item", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(InventoryTab), QCoreApplication::translate("AdministratorWindow", "Edit Inventory", nullptr));
        label->setText(QCoreApplication::translate("AdministratorWindow", "Member Name", nullptr));
        label_2->setText(QCoreApplication::translate("AdministratorWindow", "Member ID", nullptr));
        label_3->setText(QCoreApplication::translate("AdministratorWindow", "Member Type", nullptr));
        type_cb->setItemText(0, QCoreApplication::translate("AdministratorWindow", "Regular", nullptr));
        type_cb->setItemText(1, QCoreApplication::translate("AdministratorWindow", "Executive", nullptr));

        label_4->setText(QCoreApplication::translate("AdministratorWindow", "Month", nullptr));
        month_cb->setItemText(0, QCoreApplication::translate("AdministratorWindow", "1", nullptr));
        month_cb->setItemText(1, QCoreApplication::translate("AdministratorWindow", "2", nullptr));
        month_cb->setItemText(2, QCoreApplication::translate("AdministratorWindow", "3", nullptr));
        month_cb->setItemText(3, QCoreApplication::translate("AdministratorWindow", "4", nullptr));
        month_cb->setItemText(4, QCoreApplication::translate("AdministratorWindow", "5", nullptr));
        month_cb->setItemText(5, QCoreApplication::translate("AdministratorWindow", "6", nullptr));
        month_cb->setItemText(6, QCoreApplication::translate("AdministratorWindow", "7", nullptr));
        month_cb->setItemText(7, QCoreApplication::translate("AdministratorWindow", "8", nullptr));
        month_cb->setItemText(8, QCoreApplication::translate("AdministratorWindow", "9", nullptr));
        month_cb->setItemText(9, QCoreApplication::translate("AdministratorWindow", "10", nullptr));
        month_cb->setItemText(10, QCoreApplication::translate("AdministratorWindow", "11", nullptr));
        month_cb->setItemText(11, QCoreApplication::translate("AdministratorWindow", "12", nullptr));

        label_5->setText(QCoreApplication::translate("AdministratorWindow", "Day", nullptr));
        day_cb->setItemText(0, QCoreApplication::translate("AdministratorWindow", "1", nullptr));
        day_cb->setItemText(1, QCoreApplication::translate("AdministratorWindow", "2", nullptr));
        day_cb->setItemText(2, QCoreApplication::translate("AdministratorWindow", "3", nullptr));
        day_cb->setItemText(3, QCoreApplication::translate("AdministratorWindow", "4", nullptr));
        day_cb->setItemText(4, QCoreApplication::translate("AdministratorWindow", "5", nullptr));
        day_cb->setItemText(5, QCoreApplication::translate("AdministratorWindow", "6", nullptr));
        day_cb->setItemText(6, QCoreApplication::translate("AdministratorWindow", "7", nullptr));
        day_cb->setItemText(7, QCoreApplication::translate("AdministratorWindow", "8", nullptr));
        day_cb->setItemText(8, QCoreApplication::translate("AdministratorWindow", "9", nullptr));
        day_cb->setItemText(9, QCoreApplication::translate("AdministratorWindow", "10", nullptr));
        day_cb->setItemText(10, QCoreApplication::translate("AdministratorWindow", "11", nullptr));
        day_cb->setItemText(11, QCoreApplication::translate("AdministratorWindow", "12", nullptr));
        day_cb->setItemText(12, QCoreApplication::translate("AdministratorWindow", "13", nullptr));
        day_cb->setItemText(13, QCoreApplication::translate("AdministratorWindow", "14", nullptr));
        day_cb->setItemText(14, QCoreApplication::translate("AdministratorWindow", "15", nullptr));
        day_cb->setItemText(15, QCoreApplication::translate("AdministratorWindow", "16", nullptr));
        day_cb->setItemText(16, QCoreApplication::translate("AdministratorWindow", "17", nullptr));
        day_cb->setItemText(17, QCoreApplication::translate("AdministratorWindow", "18", nullptr));
        day_cb->setItemText(18, QCoreApplication::translate("AdministratorWindow", "19", nullptr));
        day_cb->setItemText(19, QCoreApplication::translate("AdministratorWindow", "20", nullptr));
        day_cb->setItemText(20, QCoreApplication::translate("AdministratorWindow", "21", nullptr));
        day_cb->setItemText(21, QCoreApplication::translate("AdministratorWindow", "22", nullptr));
        day_cb->setItemText(22, QCoreApplication::translate("AdministratorWindow", "23", nullptr));
        day_cb->setItemText(23, QCoreApplication::translate("AdministratorWindow", "24", nullptr));
        day_cb->setItemText(24, QCoreApplication::translate("AdministratorWindow", "25", nullptr));
        day_cb->setItemText(25, QCoreApplication::translate("AdministratorWindow", "26", nullptr));
        day_cb->setItemText(26, QCoreApplication::translate("AdministratorWindow", "27", nullptr));
        day_cb->setItemText(27, QCoreApplication::translate("AdministratorWindow", "28", nullptr));
        day_cb->setItemText(28, QCoreApplication::translate("AdministratorWindow", "29", nullptr));
        day_cb->setItemText(29, QCoreApplication::translate("AdministratorWindow", "30", nullptr));
        day_cb->setItemText(30, QCoreApplication::translate("AdministratorWindow", "31", nullptr));

        label_6->setText(QCoreApplication::translate("AdministratorWindow", "Year", nullptr));
        year_cb->setItemText(0, QCoreApplication::translate("AdministratorWindow", "1999", nullptr));
        year_cb->setItemText(1, QCoreApplication::translate("AdministratorWindow", "2000", nullptr));

        Add_Button->setText(QCoreApplication::translate("AdministratorWindow", "ADD", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Add_Member), QCoreApplication::translate("AdministratorWindow", "Add Member", nullptr));
        label_7->setText(QCoreApplication::translate("AdministratorWindow", "Member ID", nullptr));
        Delete_Button->setText(QCoreApplication::translate("AdministratorWindow", "DELETE", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Delete_Member), QCoreApplication::translate("AdministratorWindow", "Delete Member", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MembershipsTab), QCoreApplication::translate("AdministratorWindow", "Memberships", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorWindow: public Ui_AdministratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORWINDOW_H
