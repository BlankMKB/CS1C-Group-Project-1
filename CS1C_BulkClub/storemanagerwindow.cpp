#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

/**********************************************************
 * This is the default constructor for the StoreManager
 * Window Class. This function's purpose is to initialize
 * all the needed attributes/components apart of the
 * StoreManager Window Class.
 *********************************************************/
StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow) {
    ui->setupUi(this);

    QString memberPath, inventoryPath;
#if __APPLE__ && TARGET_OS_MAC
    memberPath = "../../../../CS1C_BulkClub/members.db";
#elif __linux__
    memberPath = "../CS1C_BulkClub/members.db";
#else
    memberPath = "..\\CS1C_BulkClub\\members.db";
#endif

#if __APPLE__ && TARGET_OS_MAC
    inventoryPath = "../../../../CS1C_BulkClub/inventory.db";
#elif __linux__
    inventoryPath = "../CS1C_BulkClub/inventory.db";
#else
    inventoryPath = "..\\CS1C_BulkClub\\inventory.db";
#endif


    this->m_pDb = new dbManager(memberPath);
    this->m_MemberList = this->m_pDb->allMembers();
    this->m_Sales = this->m_pDb->allReceipts();
    this->m_pDb->~dbManager();

    this->m_pIdb = new InventoryManager(inventoryPath);
    this->m_Inventory = this->m_pIdb->allItems();
    this->m_pIdb->~InventoryManager();

    setDropDownMenus();
}

/**********************************************************
 * This is the destructor for the StoreManagerWindow Class.
 * This function will be called when the StoreManager
 * Class goes out of scope.
 *********************************************************/
StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}

/**********************************************************
 * LOGOUT BUTTON (On-Click Event) - This is the Store
 * Manager Class function for logging a manager out of their
 * session and returning them to the MainWindow.
 *********************************************************/
void StoreManagerWindow::on_logout_button_clicked()
{
    this->hide();
    //this->parent->show();
}

void StoreManagerWindow::setTypeCB() {
    this->ui->typeCB->clear();
    this->ui->typeCB->addItem("All");
    this->ui->typeCB->addItem("Executive");
    this->ui->typeCB->addItem("Regular");
}

void StoreManagerWindow::setDateCB() {
    this->ui->dateCB->clear();
    for(int i = 1; i < 8; i++) {
        this->ui->dateCB->addItem("4/" + QString::number(i) + "/2021");
    }
}

void StoreManagerWindow::setMemberCB() {
    this->ui->memberCB->clear();

    for(const auto& member : this->m_MemberList) {
        this->ui->memberCB->addItem(member.name());
    }
}

void StoreManagerWindow::setExpirationMonthCB() {
    this->ui->expirationMonthCB->clear();
    for(int i = 1; i < 13; i++) {
        this->ui->expirationMonthCB->addItem(QString::number(i));
    }
}
void StoreManagerWindow::setDropDownMenus() {
    this->setDateCB();
    this->setTypeCB();
    this->setMemberCB();
    this->setExpirationMonthCB();
}

void StoreManagerWindow::on_dateCB_currentIndexChanged(int index) {
    clearTable(this->ui->salesByDayTW);

    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Quantity");
    this->ui->salesByDayTW->setHorizontalHeaderLabels(headerLabels);

    ui->salesByDayTW->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->salesByDayTW->setFocusPolicy(Qt::NoFocus);
    ui->salesByDayTW->setSelectionMode(QAbstractItemView::NoSelection);

    QString text = this->ui->dateCB->itemText(index);
    auto temp = text.split("/");
    int month = temp[0].toInt();
    int day = temp[1].toInt();
    int year = temp[2].toInt();
    Date date(month, day, year);
    std::vector<ItemList> salesList = this->salesListByDate(date);
    ItemList allItems;

    for(const auto& itemlist : salesList) {
        for(size_t i = 0; i < itemlist.size(); i++) {
            allItems.insertInventory(itemlist[i]);
        }
    }

    std::vector<Item*> itemList = allItems.itemList();
    std::sort(itemList.begin(), itemList.end(), std::less<Item*>());

    for(size_t i = 0; i < allItems.size(); i++) {
        this->ui->salesByDayTW->insertRow(i);
        QString itemName, itemQuantity;
        int col = 0;
        while(col < 2) {
            QTableWidgetItem* item = new QTableWidgetItem;

            switch(col) {
            case 0:
                itemName = itemList[i]->name();
                item->setText(itemName);
                break;

            case 1:
                itemQuantity = QString::number(itemList[i]->quantity());
                item->setText(itemQuantity);
                break;
            }

            item->setTextAlignment(Qt::AlignCenter);

            this->ui->salesByDayTW->setItem(i, col, item);
            col++;
        }
    }
    QHeaderView* header = this->ui->salesByDayTW->horizontalHeader();

    header->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void StoreManagerWindow::on_typeCB_currentIndexChanged(int index) {
    clearTable(this->ui->memberTypeTW);
    QStringList headerLabels;
    headerLabels.push_back("Member Name");
    headerLabels.push_back("Member ID");
    this->ui->memberTypeTW->setHorizontalHeaderLabels(headerLabels);

    int type = 0;
    int count = 0;
    QString text = this->ui->typeCB->itemText(index);
    if(text == "Executive") {
        type = 1;
    }
    else if(text == "Regular") {
        type = 2;
    }

    switch(type) {
    case 0:
        for(size_t i = 0; i < this->m_MemberList.size(); i++) {
            this->ui->memberTypeTW->insertRow(i);
            QString memberName, memberID;
            int col = 0;
            while(col < 2) {
                QTableWidgetItem* item = new QTableWidgetItem;

                switch(col) {
                case 0:
                    memberName = this->m_MemberList[i].name();
                    item->setText(memberName);
                    break;

                case 1:
                    memberID = QString::number(this->m_MemberList[i].id());
                    item->setText(memberID);
                    break;
                }

                item->setTextAlignment(Qt::AlignCenter);

                this->ui->memberTypeTW->setItem(i, col, item);
                col++;
            }
        }
        break;

    case 1:
        for(size_t i = 0; i < this->m_MemberList.size(); i++) {
            if(!this->m_MemberList[i].type()) {
                continue;
            }
            this->ui->memberTypeTW->insertRow(count);
            QString memberName, memberID;
            int col = 0;
            while(col < 2) {
                QTableWidgetItem* item = new QTableWidgetItem;

                switch(col) {
                case 0:
                    memberName = this->m_MemberList[i].name();
                    item->setText(memberName);
                    break;

                case 1:
                    memberID = QString::number(this->m_MemberList[i].id());
                    item->setText(memberID);
                    break;
                }

                item->setTextAlignment(Qt::AlignCenter);

                this->ui->memberTypeTW->setItem(count, col, item);
                col++;
            }
            count++;
        }
        break;

    case 2:
        for(size_t i = 0; i < this->m_MemberList.size(); i++) {
            if(this->m_MemberList[i].type()) {
                continue;
            }
            this->ui->memberTypeTW->insertRow(count);
            QString memberName, memberID;
            int col = 0;
            while(col < 2) {
                QTableWidgetItem* item = new QTableWidgetItem;

                switch(col) {
                case 0:
                    memberName = this->m_MemberList[i].name();
                    item->setText(memberName);
                    break;

                case 1:
                    memberID = QString::number(this->m_MemberList[i].id());
                    item->setText(memberID);
                    break;
                }

                item->setTextAlignment(Qt::AlignCenter);

                this->ui->memberTypeTW->setItem(count, col, item);
                col++;
            }
            count++;
        }
        break;
    }

    QHeaderView* header = this->ui->memberTypeTW->horizontalHeader();

    header->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void StoreManagerWindow::on_memberCB_currentIndexChanged(int index)
{

}


void StoreManagerWindow::on_expirationMonthCB_currentIndexChanged(int index)
{

}





void StoreManagerWindow::on_memberSearchButton_clicked()
{

}


void StoreManagerWindow::on_itemSearchButton_clicked()
{

}


std::vector<ItemList> StoreManagerWindow::salesListByDate(const Date& day) {
    std::vector<ItemList> salesReport;
    for(auto& x : this->m_Sales) {
        salesReport.push_back(x.second.receiptByDay(day));
    }

    return salesReport;
}

void StoreManagerWindow::clearTable(QTableWidget* tableWidget) {
    tableWidget->clear();
    int count = tableWidget->rowCount();
    while(count > 0) {
        tableWidget->removeRow(0);
        count = tableWidget->rowCount();
    }
}
