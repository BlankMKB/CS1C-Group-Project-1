#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

/**********************************************************
 * This is the default constructor for the StoreManager
 * Window Class. This function's purpose is to initialize
 * all the needed attributes/components apart of the
 * StoreManager Window Class.
 *********************************************************/
StoreManagerWindow::StoreManagerWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StoreManagerWindow) {
    this->ui->setupUi(this);

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


    m_pDb = new dbManager(memberPath);
    m_MemberList = m_pDb->allMembers();
    m_Sales = m_pDb->allReceipts();
    m_pDb->~dbManager();

    m_pIdb = new InventoryManager(inventoryPath);
    m_Inventory = m_pIdb->allItems();
    m_pIdb->~InventoryManager();

    setDropDownMenus();
    setMemberTotalsTW();
    setItemTotalsTW();
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
    hide();
    //parent->show();
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
    this->ui->memberInfoCB->clear();

    for(const auto& member : m_MemberList) {
        this->ui->memberInfoCB->addItem(member.name());
    }
}

void StoreManagerWindow::setExpirationMonthCB() {
    this->ui->expirationMonthCB->clear();
    for(int i = 1; i < 13; i++) {
        this->ui->expirationMonthCB->addItem(QString::number(i));
    }
}

void StoreManagerWindow::setDropDownMenus() {
    setDateCB();
    setTypesCB();
    setMemberCB();
    setExpirationMonthCB();
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
    clearTable(tableWidget);

    //no edits
    noEdits(tableWidget);

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
    clearTable(this->ui->memberTotalsTW);

    //no edits
    noEdits(this->ui->memberTotalsTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Member Name");
    headerLabels.push_back("Membership Number");
    headerLabels.push_back("Running Total (with tax)");
    this->ui->memberTotalsTW->setHorizontalHeaderLabels(headerLabels);

    //grand total with tax
    float total = 0;

    //local variable for m_MemberList to sort by id number
    std::vector<Member> allMembers = m_MemberList;


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

            /* switch case format:
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

            // member total (with tax)
            case 2:
                totalWTax = allMembers[i].runningTotal() + (allMembers[i].runningTotal() * SALES_TAX);
                memberTotal = "$" + QString::number(totalWTax, 'f', 2);
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

    //set total revenue string
    QString revenue = "Grand Total (with tax): $" + QString::number(total, 'f', 2);

    //set revenue text to revenue label
    this->ui->grandTotalLabel->setText(revenue);
}

void StoreManagerWindow::setItemsTW(QTableWidget* tableWidget, const ItemList& allItems, QLabel* revenueLabel) {
    //clear table
    clearTable(tableWidget);

    //set to no edits
    noEdits(tableWidget);

    //assign header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Price");
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
        QString itemName, itemPrice, itemQuantity, itemTotal;

        //set item name, then item quantity
        for(int col = 0; col < 4; col++) {
            //new item
            QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: item name
             * 1: item price
             * 2: item quantity
             * 3: item total
             */
            switch(col) {
            // item name
            case 0:
                itemName = allItems[i]->name();
                item->setText(itemName);
                break;

            // item price
            case 1:
                itemPrice = QString::number(allItems[i]->price());
                item->setText(itemPrice);
                break;

            // item quantity
            case 2:
                itemQuantity = QString::number(allItems[i]->quantity());
                item->setText(itemQuantity);
                break;

            // item total
            case 3:
                itemTotal = "$" + QString::number((allItems[i]->price() * allItems[i]->quantity()), 'f', 2);
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

    //set total revenue string
    QString revenue = "Total Revenue: $" + QString::number(salesTotal, 'f', 2);

    //set revenue text to revenue label
    revenueLabel->setText(revenue);
}

void StoreManagerWindow::setItemTotalsTW() {
    //clear table
    clearTable(this->ui->itemTotalsTW);

    //no edits
    noEdits(this->ui->itemTotalsTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Price");
    headerLabels.push_back("Item Quantity");
    headerLabels.push_back("Item Total");
    this->ui->itemTotalsTW->setHorizontalHeaderLabels(headerLabels);

    //grand total for all items
    float total = 0;

    //local variable for m_Inventory to sort by item name
    ItemList inventory = m_Inventory;

    //sort by item name
    inventory.sort();

    for(size_t i = 0; i < inventory.size(); i++) {

        //insert row
        this->ui->itemTotalsTW->insertRow(i);

        //temp name, price, quantity, total
        QString itemName, itemPrice, itemQuantity, itemTotal;

        //set item name, price, quantity, then total
        for(int col = 0; col < 4; col++) {
            //new item
            QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: item name
             * 1: item price
             * 2: item quantity
             * 3: item total
             */
            switch(col) {
            // item name
            case 0:
                itemName = inventory[i]->name();
                item->setText(itemName);
                break;

            // item price
            case 1:
                itemPrice = "$" + QString::number(inventory[i]->price(), 'f', 2);
                item->setText(itemPrice);
                break;

            // item quantity
            case 2:
                itemQuantity = QString::number(inventory[i]->quantity());
                item->setText(itemQuantity);
                break;

            // item total
            case 3:
                itemTotal = "$" + QString::number(inventory[i]->quantity() * inventory[i]->price(), 'f', 2);
                item->setText(itemTotal);
                total += (inventory[i]->quantity() * inventory[i]->price());
            }

            //align text
            item->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->itemTotalsTW->setItem(i, col, item);
        }
    }

    //resize column width to widest column
    this->ui->itemTotalsTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //clear total revenue label
    this->ui->itemTotRevLabel->clear();

    //set total revenue string
    QString revenue = "Grand Total (without tax): $" + QString::number(total, 'f', 2);

    //set revenue text to revenue label
    this->ui->itemTotRevLabel->setText(revenue);

}

//sales report by date
void StoreManagerWindow::on_dateByDayCB_currentIndexChanged(int index) {
    //selected date
    QString dateText = this->ui->dateByDayCB->itemText(index);
    Date date = parseDate(dateText);

    //get sales list by date
    std::vector<ItemList> salesList = salesListByDate(date);
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
    setItemsTW(this->ui->salesByDayTW, allItems, this->ui->totRevByDayLabel);

    //get members that shopped that day
    std::vector<Member> membersByDay = membersShoppedByDate(date);

    //set members to table
    setMembersTW(this->ui->membersByDayTW, 0, membersByDay);
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
    std::vector<Member> membersByDay = membersShoppedByDate(date);

    //set members to table
    setMembersTW(this->ui->membersByDayTW, type, membersByDay);
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
    setMembersTW(this->ui->memberTypeTW, type, m_MemberList);
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
    std::vector<Member> membersByDay = membersShoppedByDate(date);

    //set members to table
    setMembersTW(this->ui->byMemberTypeTW, type, membersByDay);

    //get sales by day
    std::vector<ItemList> salesByDay = salesListByDate(date);

    //consolidate items into one itemlist
    ItemList allItems = allItemsByType(type, date);

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
    std::vector<Member> membersByDay = membersShoppedByDate(date);

    //set members to table
    setMembersTW(this->ui->byMemberTypeTW, type, membersByDay);

    //get sales by day
    std::vector<ItemList> salesByDay = salesListByDate(date);

    //consolidate all items into one item list
    ItemList allItems = allItemsByType(type, date);

    //sort items by name
    allItems.sort();

    //set items to table
    setItemsTW(this->ui->salesByMemberTypeTW, allItems, this->ui->totRevByMemberTypeLabel);

}

//helper functions
std::vector<ItemList> StoreManagerWindow::salesListByDate(const Date& day) {
    std::vector<ItemList> salesReport;

    //for all <Member, Receipt> pairs
    for(auto& x : m_Sales) {

        //add all item lists by given day
        salesReport.push_back(x.second.receiptByDay(day));
    }

    return salesReport;
}

std::vector<Member> StoreManagerWindow::membersShoppedByDate(const Date& day) {
    std::vector<Member> membersByDay;

    //for all <Member, Receipt> pairs
    for(auto& x : m_Sales) {

        //only add members that shopped that day
        if(!x.first.receipt().receiptByDay(day).empty()) {
            membersByDay.push_back(x.first);
        }
    }

    return membersByDay;
}

ItemList StoreManagerWindow::allItemsByType(const int& type, const Date& date) {
    //get members who shopped that day
    std::vector<Member> membersByDay = membersShoppedByDate(date);

    //get sales by day
    std::vector<ItemList> salesByDay = salesListByDate(date);

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

void StoreManagerWindow::on_memberInfoCB_currentIndexChanged(int index) {
    //clear table
    this->ui->memberInfoTW->clear();

    //no edits
    noEdits(this->ui->memberInfoTW);

    //add header labels
    QStringList horizontalHeaderLabels;
    horizontalHeaderLabels.push_back("Member Information");

    QStringList verticalHeaderLabels;
    verticalHeaderLabels.push_back("Member Name");
    verticalHeaderLabels.push_back("Membership ID");
    verticalHeaderLabels.push_back("Membership Type");
    verticalHeaderLabels.push_back("Expiration Date");
    verticalHeaderLabels.push_back("Running Total");
    verticalHeaderLabels.push_back("");

    this->ui->memberInfoTW->setHorizontalHeaderLabels(horizontalHeaderLabels);
    this->ui->memberInfoTW->setVerticalHeaderLabels(verticalHeaderLabels);

    //get selected member
    QString memberText = this->ui->memberInfoCB->itemText(index);
    Member* memberInfo;
    ExecutiveMember* eMember;
    for(const auto& member : m_MemberList) {
        if(member.name() == memberText) {
            memberInfo = new Member(member);
            break;
        }
    }
    Member* pMember = memberInfo;
    if(memberInfo->type()) {
        eMember = new ExecutiveMember(*memberInfo);
        pMember = eMember;
    }

    for(size_t i = 0; i < 6; i++) {

        //temp name, id, type, expiration, running total
        QString memberName, memberID, memberType, memberExpiration, memberTotal;

        //new member
        QTableWidgetItem* member = new QTableWidgetItem;

        /* switch case format:
         * 0: member name
         * 1: member id
         * 2: member type
         * 3: member expiration
         * 4: member running total
         * 5: member rebate amount (where applicable)
         */
        switch(i) {
        // member name
        case 0:
            memberName = pMember->name();
            member->setText(memberName);
            break;

        // member id
        case 1:
            memberID = QString::number(pMember->id());
            member->setText(memberID);
            break;

        // member type
        case 2:
            if(pMember->type()) {
                member->setText("Executive");
            }
            else {
                member->setText("Regular");
            }
            break;

        // member expiration
        case 3:
            memberExpiration = pMember->expiration().dateString();
            member->setText(memberExpiration);
            break;

        // member running total
        case 4:
            memberTotal = "$" + QString::number(pMember->runningTotal(), 'f', 2);
            member->setText(memberTotal);
            break;

        // member rebate amount (if executive member)
        case 5:
            if(pMember->type()) {
                this->ui->memberInfoTW->verticalHeaderItem(5)->setText("Rebate Amount");
                member->setText("$" + QString::number((pMember->rebateAmount() * pMember->runningTotal()), 'f', 2));
            }
            break;
        }

        //align text
        member->setTextAlignment(Qt::AlignCenter);

        //add member to table
        this->ui->memberInfoTW->setItem(i, 0, member);
    }

    //resize column width to widest column
    this->ui->memberInfoTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->ui->memberInfoTW->verticalHeader()->setFixedWidth(115);
}

void StoreManagerWindow::on_expirationMonthCB_currentIndexChanged(int index) {
    //clear table
    clearTable(this->ui->expirationInfoTW);

    //no edits
    noEdits(this->ui->expirationInfoTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Member Name");
    headerLabels.push_back("Expiration Date");
    headerLabels.push_back("Renewal Fee");
    this->ui->expirationInfoTW->setHorizontalHeaderLabels(headerLabels);

    //get selected month
    int month = (this->ui->expirationMonthCB->itemText(index)).toInt();

    std::vector<Member> expirationMembers;

    for(const auto& member : m_MemberList) {
        if(member.expiration().month() == month) {
            expirationMembers.push_back(member);
        }
    }

    for(size_t i = 0; i < expirationMembers.size(); i++) {
        //insert row
        this->ui->expirationInfoTW->insertRow(i);

        //temp name, expiration date
        QString memberName, memberExpiration;

        //set member name, expiration date, then cost to renew
        for(int col = 0; col < 3; col++) {
            //new member
            QTableWidgetItem* member = new QTableWidgetItem;

            /* switch case format:
             * 0: member name
             * 1: expiration date
             * 2: renewal fee
             */
            switch(col) {
            // member name
            case 0:
                memberName = expirationMembers[i].name();
                member->setText(memberName);
                break;

            // member expiration date
            case 1:
                memberExpiration = expirationMembers[i].expiration().dateString();
                member->setText(memberExpiration);
                break;

            // member renewal fee
            case 2:
                if(expirationMembers[i].type()) {
                    member->setText("$120");
                }
                else {
                    member->setText("$65");
                }
                break;
            }

            //align text
            member->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->expirationInfoTW->setItem(i, col, member);
        }
    }

    //resize column width to widest column
    this->ui->expirationInfoTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


void StoreManagerWindow::on_itemSearchButton_clicked() {
    //clear table
    clearTable(this->ui->itemTotalsTW);

    //no edits
    noEdits(this->ui->itemTotalsTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Price");
    headerLabels.push_back("Item Quantity");
    headerLabels.push_back("Item Total");
    this->ui->itemTotalsTW->setHorizontalHeaderLabels(headerLabels);

    //get text
    QString itemText = this->ui->itemSearchLE->text();
    if(itemText == "") {
        return;
    }

    Item* pItem;
    bool found = false;

    for(const auto& items : m_Inventory.itemList()) {
        if(items->name().toUpper() == itemText.toUpper()) {
            pItem = items;
            found = true;
            break;
        }
    }

    if(!found) {
        return;
    }

    this->ui->itemTotalsTW->insertRow(0);
    for(int col = 0; col < 4; col++) {
        QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: item name
             * 1: item price
             * 2: item quantity
             * 3: item total
             */
            switch(col) {
            // item name
            case 0:
                item->setText(pItem->name());
                break;

            // item price
            case 1:
                item->setText("$" + QString::number(pItem->price(), 'f', 2));
                break;

            // item quantity
            case 2:
                item->setText(QString::number(pItem->quantity()));
                break;

            // item total
            case 3:
                item->setText("$" + QString::number(pItem->quantity() * pItem->price(), 'f', 2));
                break;
            }

            //align text
            item->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->itemTotalsTW->setItem(0, col, item);
    }

    //resize column width to widest column
    this->ui->itemTotalsTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //clear total revenue label
    this->ui->itemTotRevLabel->clear();

    //set total revenue string
    QString revenue = "Grand Total (without tax): $" + QString::number(pItem->quantity() * pItem->price(), 'f', 2);

    //set revenue text to revenue label
    this->ui->itemTotRevLabel->setText(revenue);
}


void StoreManagerWindow::on_itemResetButton_clicked() {
    setItemTotalsTW();
    this->ui->itemSearchLE->clear();
}

void StoreManagerWindow::on_memberSearchButton_clicked() {
    //get text
    QString memberText = this->ui->memberSearchLE->text();
    if(memberText == "") {
        return;
    }

    Member* pMember;
    bool found = false;

    for(auto& member : m_MemberList) {
        if(member.name().toUpper() == memberText.toUpper() || QString::number(member.id()) == memberText) {
            pMember = &member;
            found = true;
            break;
        }
    }

    if(!found) {
        return;
    }

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
    QString dateText = this->ui->dateByMemberCB->currentText();
    Date date = parseDate(dateText);

    //get members who shopped that day
    std::vector<Member> membersByDay = membersShoppedByDate(date);
    std::vector<Member> singleMember;

    for(auto& member : membersByDay) {
        if(member.name() == pMember->name() || member.id() == pMember->id()) {
            singleMember.push_back(member);
        }
    }

    setMembersTW(this->ui->byMemberTypeTW, type, singleMember);

    //consolidate items into one itemlist
    ItemList allItems = pMember->receipt().receiptByDay(date);

    //sort items by name
    allItems.sort();

    //set items to table
    setItemsTW(this->ui->salesByMemberTypeTW, allItems, this->ui->totRevByMemberTypeLabel);
}


void StoreManagerWindow::on_memberResetButton_clicked() {
    on_typeByMemberCB_currentIndexChanged(this->ui->typeByMemberCB->currentIndex());
    this->ui->memberSearchLE->clear();
}

