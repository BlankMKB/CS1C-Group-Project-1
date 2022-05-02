/********************************************************************************
** Form generated from reading UI file 'storemanagerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREMANAGERWINDOW_H
#define UI_STOREMANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreManagerWindow
{
public:
    QLabel *header_label;
    QPushButton *logout_button;
    QTabWidget *tabWidget;
    QWidget *saleByDay;
    QFrame *frame;
    QTableWidget *salesByDayTW;
    QTableWidget *memberTypeTW;
    QFrame *frame_2;
    QLabel *dateLabel;
    QComboBox *dateCB;
    QLabel *typeLabel;
    QComboBox *typeCB;
    QWidget *saleByMember;
    QFrame *frame_7;
    QTableWidget *salesByMemberTW;
    QLabel *totalPurchasesLabel;
    QFrame *frame_8;
    QLabel *memberIDLabel;
    QLineEdit *memberSearchLE;
    QPushButton *memberSearchButton;
    QWidget *memberInfo;
    QFrame *frame_3;
    QTableWidget *memberInfoTW;
    QTableWidget *rebateInfoTW;
    QTableWidget *expirationInfoTW;
    QFrame *frame_4;
    QLabel *memberLabel;
    QComboBox *memberCB;
    QLabel *rebateLabel;
    QLabel *expirationMonthLabel;
    QComboBox *expirationMonthCB;
    QWidget *items;
    QFrame *frame_5;
    QTableWidget *itemInfoTW;
    QLabel *totalRevenueLabel;
    QFrame *frame_6;
    QLabel *itemLabel;
    QLineEdit *searchLE;
    QLabel *itemSearchLabel;
    QPushButton *itemSearchButton;

    void setupUi(QDialog *StoreManagerWindow)
    {
        if (StoreManagerWindow->objectName().isEmpty())
            StoreManagerWindow->setObjectName(QString::fromUtf8("StoreManagerWindow"));
        StoreManagerWindow->resize(800, 600);
        StoreManagerWindow->setStyleSheet(QString::fromUtf8("QDialog#StoreManagerWindow{\n"
"	background: #5a6166;\n"
"}"));
        header_label = new QLabel(StoreManagerWindow);
        header_label->setObjectName(QString::fromUtf8("header_label"));
        header_label->setGeometry(QRect(0, 10, 801, 51));
        header_label->setStyleSheet(QString::fromUtf8("QLabel#header_label {\n"
"	font-size: 34px;\n"
"	font-weight: bold;\n"
"	text-decoration: overline underline;\n"
"	color:#293e78;\n"
"}"));
        header_label->setAlignment(Qt::AlignCenter);
        logout_button = new QPushButton(StoreManagerWindow);
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
        tabWidget = new QTabWidget(StoreManagerWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 60, 801, 491));
        saleByDay = new QWidget();
        saleByDay->setObjectName(QString::fromUtf8("saleByDay"));
        frame = new QFrame(saleByDay);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 110, 751, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        frame->setMidLineWidth(3);
        salesByDayTW = new QTableWidget(frame);
        if (salesByDayTW->columnCount() < 2)
            salesByDayTW->setColumnCount(2);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        salesByDayTW->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        salesByDayTW->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        salesByDayTW->setObjectName(QString::fromUtf8("salesByDayTW"));
        salesByDayTW->setGeometry(QRect(20, 30, 271, 271));
        salesByDayTW->horizontalHeader()->setCascadingSectionResizes(false);
        salesByDayTW->verticalHeader()->setCascadingSectionResizes(false);
        memberTypeTW = new QTableWidget(frame);
        if (memberTypeTW->columnCount() < 2)
            memberTypeTW->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        memberTypeTW->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        memberTypeTW->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        memberTypeTW->setObjectName(QString::fromUtf8("memberTypeTW"));
        memberTypeTW->setGeometry(QRect(460, 30, 271, 271));
        frame_2 = new QFrame(saleByDay);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 30, 751, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        frame_2->setMidLineWidth(3);
        dateLabel = new QLabel(frame_2);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(10, 10, 251, 21));
        QFont font1;
        font1.setPointSize(12);
        dateLabel->setFont(font1);
        dateCB = new QComboBox(frame_2);
        dateCB->setObjectName(QString::fromUtf8("dateCB"));
        dateCB->setGeometry(QRect(10, 40, 253, 23));
        dateCB->setFont(font1);
        typeLabel = new QLabel(frame_2);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setGeometry(QRect(470, 10, 251, 21));
        typeLabel->setFont(font1);
        typeCB = new QComboBox(frame_2);
        typeCB->setObjectName(QString::fromUtf8("typeCB"));
        typeCB->setGeometry(QRect(470, 40, 253, 23));
        typeCB->setFont(font1);
        tabWidget->addTab(saleByDay, QString());
        saleByMember = new QWidget();
        saleByMember->setObjectName(QString::fromUtf8("saleByMember"));
        frame_7 = new QFrame(saleByMember);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(20, 110, 751, 331));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Plain);
        frame_7->setLineWidth(2);
        frame_7->setMidLineWidth(3);
        salesByMemberTW = new QTableWidget(frame_7);
        if (salesByMemberTW->columnCount() < 3)
            salesByMemberTW->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        salesByMemberTW->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        salesByMemberTW->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        salesByMemberTW->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        salesByMemberTW->setObjectName(QString::fromUtf8("salesByMemberTW"));
        salesByMemberTW->setGeometry(QRect(230, 20, 281, 271));
        salesByMemberTW->horizontalHeader()->setCascadingSectionResizes(false);
        salesByMemberTW->verticalHeader()->setCascadingSectionResizes(false);
        totalPurchasesLabel = new QLabel(frame_7);
        totalPurchasesLabel->setObjectName(QString::fromUtf8("totalPurchasesLabel"));
        totalPurchasesLabel->setGeometry(QRect(530, 250, 171, 41));
        frame_8 = new QFrame(saleByMember);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(20, 30, 751, 81));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        frame_8->setLineWidth(2);
        frame_8->setMidLineWidth(3);
        memberIDLabel = new QLabel(frame_8);
        memberIDLabel->setObjectName(QString::fromUtf8("memberIDLabel"));
        memberIDLabel->setGeometry(QRect(330, 20, 111, 21));
        memberIDLabel->setFont(font1);
        memberSearchLE = new QLineEdit(frame_8);
        memberSearchLE->setObjectName(QString::fromUtf8("memberSearchLE"));
        memberSearchLE->setGeometry(QRect(330, 50, 111, 21));
        memberSearchButton = new QPushButton(frame_8);
        memberSearchButton->setObjectName(QString::fromUtf8("memberSearchButton"));
        memberSearchButton->setGeometry(QRect(450, 50, 80, 22));
        tabWidget->addTab(saleByMember, QString());
        memberInfo = new QWidget();
        memberInfo->setObjectName(QString::fromUtf8("memberInfo"));
        frame_3 = new QFrame(memberInfo);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 110, 751, 331));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(3);
        memberInfoTW = new QTableWidget(frame_3);
        if (memberInfoTW->columnCount() < 1)
            memberInfoTW->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setText(QString::fromUtf8("Member Information"));
        __qtablewidgetitem7->setFont(font);
        memberInfoTW->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        if (memberInfoTW->rowCount() < 5)
            memberInfoTW->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        memberInfoTW->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        memberInfoTW->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        memberInfoTW->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        memberInfoTW->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        memberInfoTW->setVerticalHeaderItem(4, __qtablewidgetitem12);
        memberInfoTW->setObjectName(QString::fromUtf8("memberInfoTW"));
        memberInfoTW->setGeometry(QRect(20, 10, 241, 251));
        rebateInfoTW = new QTableWidget(frame_3);
        if (rebateInfoTW->columnCount() < 2)
            rebateInfoTW->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        rebateInfoTW->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setText(QString::fromUtf8("Rebate Amount"));
        __qtablewidgetitem14->setFont(font);
        rebateInfoTW->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        rebateInfoTW->setObjectName(QString::fromUtf8("rebateInfoTW"));
        rebateInfoTW->setGeometry(QRect(270, 10, 221, 251));
        expirationInfoTW = new QTableWidget(frame_3);
        if (expirationInfoTW->columnCount() < 2)
            expirationInfoTW->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        expirationInfoTW->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setText(QString::fromUtf8("Expiration Date"));
        __qtablewidgetitem16->setFont(font);
        expirationInfoTW->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        expirationInfoTW->setObjectName(QString::fromUtf8("expirationInfoTW"));
        expirationInfoTW->setGeometry(QRect(500, 10, 231, 251));
        frame_4 = new QFrame(memberInfo);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(20, 30, 751, 81));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        frame_4->setMidLineWidth(3);
        memberLabel = new QLabel(frame_4);
        memberLabel->setObjectName(QString::fromUtf8("memberLabel"));
        memberLabel->setGeometry(QRect(10, 10, 251, 21));
        memberLabel->setFont(font1);
        memberCB = new QComboBox(frame_4);
        memberCB->setObjectName(QString::fromUtf8("memberCB"));
        memberCB->setGeometry(QRect(10, 40, 221, 23));
        memberCB->setFont(font1);
        rebateLabel = new QLabel(frame_4);
        rebateLabel->setObjectName(QString::fromUtf8("rebateLabel"));
        rebateLabel->setGeometry(QRect(330, 30, 61, 21));
        rebateLabel->setFont(font1);
        expirationMonthLabel = new QLabel(frame_4);
        expirationMonthLabel->setObjectName(QString::fromUtf8("expirationMonthLabel"));
        expirationMonthLabel->setGeometry(QRect(530, 10, 161, 21));
        expirationMonthLabel->setFont(font1);
        expirationMonthCB = new QComboBox(frame_4);
        expirationMonthCB->setObjectName(QString::fromUtf8("expirationMonthCB"));
        expirationMonthCB->setGeometry(QRect(530, 40, 181, 23));
        expirationMonthCB->setFont(font1);
        tabWidget->addTab(memberInfo, QString());
        items = new QWidget();
        items->setObjectName(QString::fromUtf8("items"));
        frame_5 = new QFrame(items);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(20, 110, 751, 331));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Plain);
        frame_5->setLineWidth(2);
        frame_5->setMidLineWidth(3);
        itemInfoTW = new QTableWidget(frame_5);
        if (itemInfoTW->columnCount() < 4)
            itemInfoTW->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setText(QString::fromUtf8("Name"));
        __qtablewidgetitem17->setFont(font);
        itemInfoTW->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        itemInfoTW->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        itemInfoTW->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        itemInfoTW->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        itemInfoTW->setObjectName(QString::fromUtf8("itemInfoTW"));
        itemInfoTW->setGeometry(QRect(180, 20, 371, 301));
        itemInfoTW->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        itemInfoTW->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        totalRevenueLabel = new QLabel(frame_5);
        totalRevenueLabel->setObjectName(QString::fromUtf8("totalRevenueLabel"));
        totalRevenueLabel->setGeometry(QRect(560, 280, 171, 41));
        frame_6 = new QFrame(items);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(20, 30, 751, 81));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(2);
        frame_6->setMidLineWidth(3);
        itemLabel = new QLabel(frame_6);
        itemLabel->setObjectName(QString::fromUtf8("itemLabel"));
        itemLabel->setGeometry(QRect(330, 20, 81, 21));
        itemLabel->setFont(font1);
        itemLabel->setTextFormat(Qt::MarkdownText);
        searchLE = new QLineEdit(frame_6);
        searchLE->setObjectName(QString::fromUtf8("searchLE"));
        searchLE->setGeometry(QRect(520, 50, 131, 23));
        itemSearchLabel = new QLabel(frame_6);
        itemSearchLabel->setObjectName(QString::fromUtf8("itemSearchLabel"));
        itemSearchLabel->setGeometry(QRect(520, 20, 141, 21));
        itemSearchLabel->setFont(font1);
        itemSearchLabel->setTextFormat(Qt::MarkdownText);
        itemSearchButton = new QPushButton(frame_6);
        itemSearchButton->setObjectName(QString::fromUtf8("itemSearchButton"));
        itemSearchButton->setGeometry(QRect(660, 50, 80, 22));
        tabWidget->addTab(items, QString());

        retranslateUi(StoreManagerWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StoreManagerWindow);
    } // setupUi

    void retranslateUi(QDialog *StoreManagerWindow)
    {
        StoreManagerWindow->setWindowTitle(QCoreApplication::translate("StoreManagerWindow", "Dialog", nullptr));
        header_label->setText(QCoreApplication::translate("StoreManagerWindow", "Store Manager", nullptr));
        logout_button->setText(QCoreApplication::translate("StoreManagerWindow", "Logout Now", nullptr));
        QTableWidgetItem *___qtablewidgetitem = salesByDayTW->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StoreManagerWindow", "Item Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = salesByDayTW->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StoreManagerWindow", "Item Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = memberTypeTW->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StoreManagerWindow", "Members", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = memberTypeTW->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StoreManagerWindow", "Member ID", nullptr));
        dateLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Select Date: ", nullptr));
        typeLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Sort by type: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(saleByDay), QCoreApplication::translate("StoreManagerWindow", "Sales Report by Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = salesByMemberTW->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StoreManagerWindow", "Item Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = salesByMemberTW->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StoreManagerWindow", "Item Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = salesByMemberTW->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("StoreManagerWindow", "Item Quantity", nullptr));
        totalPurchasesLabel->setText(QCoreApplication::translate("StoreManagerWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Total Revenue: </span></p></body></html>", nullptr));
        memberIDLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Member name/id:", nullptr));
        memberSearchButton->setText(QCoreApplication::translate("StoreManagerWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(saleByMember), QCoreApplication::translate("StoreManagerWindow", "Sales Report by Member", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = memberInfoTW->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("StoreManagerWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = memberInfoTW->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("StoreManagerWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = memberInfoTW->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("StoreManagerWindow", "Member Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = memberInfoTW->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("StoreManagerWindow", "Expiration Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = memberInfoTW->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("StoreManagerWindow", "Running Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = rebateInfoTW->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("StoreManagerWindow", "Member", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = expirationInfoTW->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("StoreManagerWindow", "Member", nullptr));
        memberLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Select Member: ", nullptr));
        rebateLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Rebates", nullptr));
        expirationMonthLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Select Month: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(memberInfo), QCoreApplication::translate("StoreManagerWindow", "Member Information", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = itemInfoTW->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("StoreManagerWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = itemInfoTW->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("StoreManagerWindow", "Quantity Sold", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = itemInfoTW->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("StoreManagerWindow", "Item Revenue", nullptr));
        totalRevenueLabel->setText(QCoreApplication::translate("StoreManagerWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Total Revenue: </span></p></body></html>", nullptr));
        itemLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Item Report", nullptr));
        itemSearchLabel->setText(QCoreApplication::translate("StoreManagerWindow", "Search by Item Name", nullptr));
        itemSearchButton->setText(QCoreApplication::translate("StoreManagerWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(items), QCoreApplication::translate("StoreManagerWindow", "Items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreManagerWindow: public Ui_StoreManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREMANAGERWINDOW_H
