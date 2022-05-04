#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

/**********************************************************
 * This is the default constructor for the StoreManager
 * Window Class. This function's purpose is to initialize
 * all the needed attributes/components apart of the
 * StoreManager Window Class.
 *********************************************************/
StoreManagerWindow::StoreManagerWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StoreManagerWindow) {
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
    setMemberTotalsTW();
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

Date StoreManagerWindow::parseDate(const QString& line) {

    /* line format:
     * 0: month
     * 1: day
     * 2: year
     */
    auto temp = line.split("/");
    int month = temp[0].toInt();
    int day = temp[1].toInt();
    int year = temp[2].toInt();

    return Date(month, day, year);
}

//set drop down menus
void StoreManagerWindow::setTypesCB() {
    this->ui->memberTypeCB->clear();
    this->ui->memberTypeCB->addItem("All");
    this->ui->memberTypeCB->addItem("Executive");
    this->ui->memberTypeCB->addItem("Regular");

    this->ui->dateTypeByDayCB->clear();
    this->ui->dateTypeByDayCB->addItem("All");
    this->ui->dateTypeByDayCB->addItem("Executive");
    this->ui->dateTypeByDayCB->addItem("Regular");

    this->ui->typeByMemberCB->clear();
    this->ui->typeByMemberCB->addItem("All");
    this->ui->typeByMemberCB->addItem("Executive");
    this->ui->typeByMemberCB->addItem("Regular");

}

void StoreManagerWindow::setDateCB() {
    this->ui->dateByDayCB->clear();
    this->ui->dateByMemberCB->clear();
    for(int i = 1; i < 8; i++) {
        this->ui->dateByDayCB->addItem("4/" + QString::number(i) + "/2021");
        this->ui->dateByMemberCB->addItem("4/" + QString::number(i) + "/2021");
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
    this->setTypesCB();
    this->setMemberCB();
    this->setExpirationMonthCB();
}

//no editing table
void StoreManagerWindow::noEdits(QTableWidget* tableWidget) {
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

}

void StoreManagerWindow::clearTable(QTableWidget* tableWidget) {
    tableWidget->clear();
    int count = tableWidget->rowCount();
    while(count > 0) {
        tableWidget->removeRow(0);
        count = tableWidget->rowCount();
    }
}

//helper functions to set tablewidgets
void StoreManagerWindow::setMembersTW(QTableWidget* tableWidget, const int& type, const std::vector<Member>& membersByDay) {
    //clear table
    this->clearTable(tableWidget);

    //no edits
    this->noEdits(tableWidget);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Member Name");
    headerLabels.push_back("Member ID");
    tableWidget->setHorizontalHeaderLabels(headerLabels);

    int count = 0;

    /* switch case format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    switch(type) {

    //all members
    case 0:
        for(size_t i = 0; i < membersByDay.size(); i++) {
            //insert row
            tableWidget->insertRow(i);

            //temp name and id
            QString memberName, memberID;

            for(int col = 0; col < 2; col++) {
                QTableWidgetItem* item = new QTableWidgetItem;

                /* switch case format:
                 * 0: member name
                 * 1: member id
                 */
                switch(col) {
                // member name
                case 0:
                    memberName = membersByDay[i].name();
                    item->setText(memberName);
                    break;

                //member id
                case 1:
                    memberID = QString::number(membersByDay[i].id());
                    item->setText(memberID);
                    break;
                }

                //align text to center
                item->setTextAlignment(Qt::AlignCenter);

                //add item to table
                tableWidget->setItem(i, col, item);
            }
        }
        break;

    // executive member
    case 1:
        for(size_t i = 0; i < membersByDay.size(); i++) {
            //only add executive members
            if(!membersByDay[i].type()) {
                continue;
            }

            //insert row
            tableWidget->insertRow(count);

            //temp name and id
            QString memberName, memberID;

            for(int col = 0; col < 2; col++) {
                QTableWidgetItem* item = new QTableWidgetItem;

                /* switch case format:
                 * 0: member name
                 * 1: member id
                 */
                switch(col) {
                // member name
                case 0:
                    memberName = membersByDay[i].name();
                    item->setText(memberName);
                    break;

                //member id
                case 1:
                    memberID = QString::number(membersByDay[i].id());
                    item->setText(memberID);
                    break;
                }

                //align text to center
                item->setTextAlignment(Qt::AlignCenter);

                //add item to table
                tableWidget->setItem(count, col, item);
            }
            count++;
        }
        break;

    // regular members
    case 2:
        for(size_t i = 0; i < membersByDay.size(); i++) {
            //only add regular members
            if(membersByDay[i].type()) {
                continue;
            }

            //insert row
            tableWidget->insertRow(count);

            //temp name and id
            QString memberName, memberID;

            for(int col = 0; col < 2; col++) {
                QTableWidgetItem* item = new QTableWidgetItem;

                /* switch case format:
                 * 0: member name
                 * 1: member id
                 */
                switch(col) {
                //member name
                case 0:
                    memberName = membersByDay[i].name();
                    item->setText(memberName);
                    break;

                //member id
                case 1:
                    memberID = QString::number(membersByDay[i].id());
                    item->setText(memberID);
                    break;
                }

                //align text to center
                item->setTextAlignment(Qt::AlignCenter);

                //add item to table
                tableWidget->setItem(count, col, item);
            }
            count++;
        }
        break;
    }

    //resize column width to widest column
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void StoreManagerWindow::setMemberTotalsTW() {
    //clear table
    this->clearTable(this->ui->memberTotalsTW);

    //no edits
    this->noEdits(this->ui->memberTotalsTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Member Name");
    headerLabels.push_back("Membership Number");
    headerLabels.push_back("Running Total (with tax)");
    this->ui->memberTotalsTW->setHorizontalHeaderLabels(headerLabels);

    //grand total with tax
    float total = 0;

    //local variable for m_MemberList to sort by id number
    std::vector<Member> allMembers = this->m_MemberList;


    std::sort(allMembers.begin(), allMembers.end(), std::less<Member>());

    for(size_t i = 0; i < allMembers.size(); i++) {
        //insert row
        this->ui->memberTotalsTW->insertRow(i);

        //temp name, id, total
        QString memberName, memberId, memberTotal;

        //temp total with tax
        float totalWTax = 0;

        //set member name, id, then total
        for(int col = 0; col < 3; col++) {
            //new member
            QTableWidgetItem* member = new QTableWidgetItem;

            /* switch case format;
             * 0: member name
             * 1: member id
             * 2: member total (with tax)
             */
            switch(col) {
            // member name
            case 0:
                memberName = allMembers[i].name();
                member->setText(memberName);
                break;

            // member id
            case 1:
                memberId = QString::number(allMembers[i].id());
                member->setText(memberId);
                break;

            //member total (with tax)
            case 2:
                totalWTax = (float) ((int) ((allMembers[i].runningTotal() + (allMembers[i].runningTotal() * SALES_TAX)) * 100) / 100.0);
                memberTotal = "$" + QString::number(totalWTax);
                member->setText(memberTotal);
                total += totalWTax;
                break;
            }

            //align text
            member->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->memberTotalsTW->setItem(i, col, member);
        }
    }

    //resize column width to widest column
    this->ui->memberTotalsTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //clear total revenue label
    this->ui->grandTotalLabel->clear();

    //round to 2 decimals
    int temp = total * 100;
    total = temp / 100.0;

    //set total revenue string
    QString revenue = "Grand Total (with tax): $" + QString::number(total);

    //set revenue text to revenue label
    this->ui->grandTotalLabel->setText(revenue);
}

void StoreManagerWindow::setItemsTW(QTableWidget* tableWidget, const ItemList& allItems, QLabel* revenueLabel) {
    //clear table
    this->clearTable(tableWidget);

    //set to no edits
    this->noEdits(tableWidget);

    //assign header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Quantity");
    headerLabels.push_back("Item Total");
    tableWidget->setHorizontalHeaderLabels(headerLabels);

    //total amount before tax
    float total = 0;

    //insert items into table
    for(size_t i = 0; i < allItems.size(); i++) {
        //insert row
        tableWidget->insertRow(i);

        //temp name, quantity, item total (quantity * price)
        QString itemName, itemQuantity, itemTotal;

        //set item name, then item quantity
        for(int col = 0; col < 3; col++) {
            //new item
            QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: item name
             * 1: item quantity
             * 2: item total
             */
            switch(col) {
            // item name
            case 0:
                itemName = allItems[i]->name();
                item->setText(itemName);
                break;

            // item quantity
            case 1:
                itemQuantity = QString::number(allItems[i]->quantity());
                item->setText(itemQuantity);
                break;

            // item total
            case 2:
                itemTotal = "$" + QString::number(allItems[i]->price() * allItems[i]->quantity());
                item->setText(itemTotal);
                total += (allItems[i]->price() * allItems[i]->quantity());
                break;
            }

            //align text
            item->setTextAlignment(Qt::AlignCenter);

            //add item to table
            tableWidget->setItem(i, col, item);
        }
    }

    //resize column width to widest column
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //clear total revenue label
    revenueLabel->clear();

    //calculate total with sales
    float salesTotal = total + (total * SALES_TAX);

    //round to 2 decimals
    int temp = salesTotal * 100;
    salesTotal = temp / 100.0;

    //set total revenue string
    QString revenue = "Total Revenue: $" + QString::number(salesTotal);

    //set revenue text to revenue label
    revenueLabel->setText(revenue);
}

//sales report by date
void StoreManagerWindow::on_dateByDayCB_currentIndexChanged(int index) {
    //selected date
    QString dateText = this->ui->dateByDayCB->itemText(index);
    Date date = parseDate(dateText);

    //get sales list by date
    std::vector<ItemList> salesList = this->salesListByDate(date);
    ItemList allItems;

    //consolidate all items into one item list
    for(const auto& itemlist : salesList) {
        for(size_t i = 0; i < itemlist.size(); i++) {
            allItems.insertInventory(itemlist[i]);
        }
    }

    //sort items by name
    allItems.sort();

    //set items to table
    this->setItemsTW(this->ui->salesByDayTW, allItems, this->ui->totRevByDayLabel);

    //get members that shopped that day
    std::vector<Member> membersByDay = this->membersShoppedByDate(date);

    //set members to table
    this->setMembersTW(this->ui->membersByDayTW, 0, membersByDay);
}

void StoreManagerWindow::on_dateTypeByDayCB_currentIndexChanged(int index) {
    /* type format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    int type = 0;

    //selected type
    QString typeText = this->ui->dateTypeByDayCB->itemText(index);

    //assign type
    if(typeText == "Executive") {
        type = 1;
    }
    else if(typeText == "Regular") {
        type = 2;
    }

    //current date
    QString dateText = this->ui->dateByDayCB->currentText();
    Date date = parseDate(dateText);

    //get members who shopped that day
    std::vector<Member> membersByDay = this->membersShoppedByDate(date);

    //set members to table
    this->setMembersTW(this->ui->membersByDayTW, type, membersByDay);
}

//member information
void StoreManagerWindow::on_memberTypeCB_currentIndexChanged(int index) {
    /* type format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    int type = 0;
    QString text = this->ui->memberTypeCB->itemText(index);

    //assign type
    if(text == "Executive") {
        type = 1;
    }
    else if(text == "Regular") {
        type = 2;
    }

    //set members to table
    this->setMembersTW(this->ui->memberTypeTW, type, this->m_MemberList);
}


//sales report by member type
void StoreManagerWindow::on_dateByMemberCB_currentIndexChanged(int index) {
    //current type
    QString typeText = this->ui->typeByMemberCB->currentText();

    /* type format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    int type = 0;

    //assign type
    if(typeText == "Executive") {
        type = 1;
    }
    else if(typeText == "Regular") {
        type = 2;
    }

    //selected date
    QString dateText = this->ui->dateByMemberCB->itemText(index);
    Date date = parseDate(dateText);

    //get members who shopped that day
    std::vector<Member> membersByDay = this->membersShoppedByDate(date);

    //set members to table
    this->setMembersTW(this->ui->byMemberTypeTW, type, membersByDay);

    //get sales by day
    std::vector<ItemList> salesByDay = this->salesListByDate(date);

    //consolidate items into one itemlist
    ItemList allItems = this->allItemsByType(type, date);

    //sort items by name
    allItems.sort();

    //set items to table
    setItemsTW(this->ui->salesByMemberTypeTW, allItems, this->ui->totRevByMemberTypeLabel);
}

void StoreManagerWindow::on_typeByMemberCB_currentIndexChanged(int index) {
    //selected type
    QString typeText = this->ui->typeByMemberCB->itemText(index);

    /* type format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    int type = 0;

    //assign type
    if(typeText == "Executive") {
        type = 1;
    }
    else if(typeText == "Regular") {
        type = 2;
    }

    //current date
    QString dateText = this->ui->dateByMemberCB->currentText();
    Date date = parseDate(dateText);

    //get members that shopped that day
    std::vector<Member> membersByDay = this->membersShoppedByDate(date);

    //set members to table
    this->setMembersTW(this->ui->byMemberTypeTW, type, membersByDay);

    //get sales by day
    std::vector<ItemList> salesByDay = this->salesListByDate(date);

    //consolidate all items into one item list
    ItemList allItems = this->allItemsByType(type, date);

    //sort items by name
    allItems.sort();

    //set items to table
    setItemsTW(this->ui->salesByMemberTypeTW, allItems, this->ui->totRevByMemberTypeLabel);

}




//helper functions
std::vector<ItemList> StoreManagerWindow::salesListByDate(const Date& day) {
    std::vector<ItemList> salesReport;

    //for all <Member, Receipt> pairs
    for(auto& x : this->m_Sales) {

        //add all item lists by given day
        salesReport.push_back(x.second.receiptByDay(day));
    }

    return salesReport;
}

std::vector<Member> StoreManagerWindow::membersShoppedByDate(const Date& day) {
    std::vector<Member> membersByDay;

    //for all <Member, Receipt> pairs
    for(auto& x : this->m_Sales) {

        //only add members that shopped that day
        if(!x.first.receipt().receiptByDay(day).empty()) {
            membersByDay.push_back(x.first);
        }
    }

    return membersByDay;
}

ItemList StoreManagerWindow::allItemsByType(const int& type, const Date& date) {
    //get members who shopped that day
    std::vector<Member> membersByDay = this->membersShoppedByDate(date);

    //get sales by day
    std::vector<ItemList> salesByDay = this->salesListByDate(date);

    ItemList allItems;

    /* type format:
     * 0: all members
     * 1: executive members
     * 2: regular members
     */
    switch(type) {
    //all members
    case 0:

        //for all itemlists in sales by day
        for(const auto& itemlist : salesByDay) {

            //consolidate all items into one item list
            for(size_t i = 0; i < itemlist.size(); i++) {
                allItems.insertInventory(itemlist[i]);
            }
        }
        break;

    //executive members
    case 1:

        //for all members that shopped that day
        for(const auto& member : membersByDay) {

            //only add executive member purchases
            if(member.type()) {
                ItemList receipt = member.receipt().receiptByDay(date);
                for(size_t i = 0; i < receipt.size(); i++) {
                    allItems.insertInventory(receipt[i]);
                }
            }
        }
        break;

    //regular members
    case 2:

        //for all members that shopped that day
        for(const auto& member : membersByDay) {

            //only add regular member purchases
            if(!member.type()) {
                ItemList receipt = member.receipt().receiptByDay(date);
                for(size_t i = 0; i < receipt.size(); i++) {
                    allItems.insertInventory(receipt[i]);
                }
            }
        }
        break;

    //default
    default:
        break;
    }

    return allItems;
}







