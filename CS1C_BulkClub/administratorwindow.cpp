#include "administratorwindow.h"
#include "ui_administratorwindow.h"
#include "mainwindow.h"

/**********************************************************
 * This is the default constructor for the Administrator
 * Window Class. This function will initialize all needed
 * components/attributes within the Administrator Window
 * Class.
 *********************************************************/
AdministratorWindow::AdministratorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministratorWindow)
{
    ui->setupUi(this);
    this->parent = this->parentWidget();

    this->ui->memberIDLE->setValidator( new QIntValidator(0, 10000000, this) );


    m_pDb = new DbManager(MEMBERS_PATH);
    m_MemberList = m_pDb->AllMembers();
    delete m_pDb;

    m_pIdb = new InventoryManager(INVENTORY_PATH);
    m_Inventory = m_pIdb->AllItems();
    delete m_pIdb;

    UpdateAll();
}

/**********************************************************
 * This is the destructor for AdministratorWindow Class.
 * This function will be called when the Administrator
 * Window Class goes out of scope.
 *********************************************************/
AdministratorWindow::~AdministratorWindow()
{
    delete ui;
}

/**********************************************************
 * LOGOUT BUTTON (On-Click Event) - This clas function is
 * for logging an administrator our of the session and
 * returning them to the MainWindow.
 *********************************************************/
void AdministratorWindow::on_logout_button_clicked()
{
   this->hide();
   //this->parent->show();
}

// members
void AdministratorWindow::on_addMemberButton_clicked() {
    m_pDb = new DbManager(MEMBERS_PATH);

    if(this->ui->memberNameLE->text() == ""
            || this->ui->memberIDLE->text() == ""
            || this->ui->memberTypeLE->text() == ""
            || this->ui->memberExpirationLE->text() == "") {
        QMessageBox::critical(this, "Error", "One or more text fields are empty");
        return;
    }

    if(this->ui->memberExpirationLE->text().count('/') != 2) {
        QMessageBox::critical(this, "Error", "Please input date in the format MM/DD/YYYY");
        return;
    }

    if(this->ui->memberTypeLE->text().toUpper() != "EXECUTIVE" && this->ui->memberTypeLE->text().toUpper() != "REGULAR") {
        QMessageBox::critical(this, "Error", "Invalid member type (Executive or Regular)");
        return;
    }


    QString name = this->ui->memberNameLE->text();
    int id = this->ui->memberIDLE->text().toInt();
    bool type = this->ui->memberTypeLE->text().toUpper() == "EXECUTIVE" ? true : false;
    Date date = Date::ParseDate(this->ui->memberExpirationLE->text());

    Member* pNewMember;
    if(type) {
        ExecutiveMember newMember(name, id, type, date);
        pNewMember = &newMember;
    }
    else {
        Member newMember(name, id, type, date);
        pNewMember = &newMember;
    }

    m_pDb->AddMember(*pNewMember);
    m_MemberList.clear();
    m_MemberList = m_pDb->AllMembers();

    this->ui->memberNameLE->clear();
    this->ui->memberIDLE->clear();
    this->ui->memberTypeLE->clear();
    this->ui->memberExpirationLE->clear();

    UpdateAll();
    delete m_pDb;
}

void AdministratorWindow::on_updateMembersButton_clicked() {
    m_pDb = new DbManager(MEMBERS_PATH);

    for(const auto& member : m_MemberList) {
        m_pDb->UpdateMember(member);
    }

    m_MemberList = m_pDb->AllMembers();

    UpdateAll();

    delete m_pDb;
}

void AdministratorWindow::on_editMembersTW_cellChanged(int row, int column) {
    Member* p_EditedMember = nullptr;
    for(auto& member : m_MemberList) {
        if(member.Name() == this->ui->editMembersTW->item(row, 0)->text()) {
            p_EditedMember = &member;
            break;
        }
    }

    if(!p_EditedMember) {
        return;
    }

    bool wasRegular = p_EditedMember->Type();

    QString editedText = this->ui->editMembersTW->item(row, column)->text();

    switch(column) {
    case 0:
        p_EditedMember->SetName(editedText);
        break;
    case 1:
        p_EditedMember->SetID(editedText.toInt());
        break;
    case 2:
        p_EditedMember->SetType(editedText.toUpper() == "EXECUTIVE" ? true : false);
        if(!wasRegular && p_EditedMember->Type()) {
            p_EditedMember->SetRunningTotal(p_EditedMember->RunningTotal() + 55);
        }
        break;
    case 3:
        if(this->ui->editMembersTW->item(row, column)->text().count('/') != 2) {
            QMessageBox::critical(this, "Error", "Please input date in the format MM/DD/YYYY");
            break;
        }
            p_EditedMember->SetExpiration(Date::ParseDate(editedText));
        break;
    case 4:
        if(editedText.contains("$")) {
            break;
        }
        p_EditedMember->SetRunningTotal(editedText.toFloat());
        break;
    }
}

void AdministratorWindow::on_deleteMemberButton_clicked() {
    m_pDb = new DbManager(MEMBERS_PATH);

    QString name = this->ui->deleteMemberCB->currentText();

    for(size_t i = 0; i < m_MemberList.size(); i++) {
        if(m_MemberList[i].Name() == name) {
            if(m_pDb->DeleteMemberById(m_MemberList[i].Id())) {
                qDebug().noquote().nospace() << "Member " << m_MemberList[i].Name() << " deleted successfully";
                m_MemberList.erase(m_MemberList.begin() + i);
            }
            UpdateAll();
            break;
        }
    }
    delete m_pDb;
}





// items
void AdministratorWindow::on_addItemButton_clicked() {
    m_pIdb = new InventoryManager(INVENTORY_PATH);

    if(this->ui->addItemNameLE->text() == "") {
        QMessageBox::critical(this, "Error", "One or more text fields are empty");
        return;
    }


    QString name = this->ui->addItemNameLE->text();
    float price = static_cast<float>(this->ui->addItemPriceDSB->value());

    Item* item = new Item(name, price, 0);

    m_pIdb->AddItem(item);
    m_Inventory.Insert(item);


    this->ui->addItemNameLE->clear();
    this->ui->addItemPriceDSB->clear();

    UpdateAll();

    delete m_pIdb;
}

void AdministratorWindow::on_editItemsTW_cellChanged(int row, int column) {
    if(m_Setting) {
        return;
    }

    Item* p_Item = nullptr, *p_NewItem = nullptr;

    QString editedText = this->ui->editItemsTW->item(row, column)->text();
    QString name = this->ui->editItemsTW->item(row, 0)->text();

    for(size_t i = 0; i < m_Inventory.size(); i++) {
        if((m_Inventory[i]->Name() == name)) {
            p_Item = m_Inventory[i];
            break;
        }
    }

    if(!p_Item) {
        return;
    }

    switch(column) {
    case 0:
        p_Item->SetName(editedText);
        return;
    case 1:
        if(editedText.contains("$")) {
            return;
        }
        p_Item->SetPrice(editedText.toFloat());
        p_Item->SetQuantity(0);
        break;
    case 2:
        if(editedText.contains("units")) {
            return;
        }
        p_Item->SetQuantity(editedText.toInt());
        return;
    default:
        if(editedText.contains("$")) {
            return;
        }
        return;
    }
}

void AdministratorWindow::on_updateItemsButton_clicked() {
    m_pIdb = new InventoryManager(INVENTORY_PATH);

    for(size_t i = 0; i < m_Inventory.size(); i++) {
        m_pIdb->UpdateItem(m_Inventory[i]);
    }

    m_Inventory = m_pIdb->AllItems();

    UpdateAll();

    delete m_pIdb;
}

void AdministratorWindow::on_deleteItemButton_clicked() {
    m_pIdb = new InventoryManager(INVENTORY_PATH);

    QString name = this->ui->deleteItemCB->currentText();

    for(size_t i = 0; i < m_Inventory.size(); i++) {
        if(m_Inventory[i]->Name() == name) {
            if(m_pIdb->DeleteItemByName(name)) {
                qDebug().noquote().nospace() << "Item " << m_Inventory[i]->Name() << " deleted successfully";
                m_Inventory.RemoveItem(m_Inventory[i]->Name());
            }
            UpdateAll();
            break;
        }
    }
    delete m_pIdb;
}





// members
void AdministratorWindow::SetMembersCB() {
    this->ui->deleteMemberCB->clear();
    for(const auto& member : m_MemberList) {
        this->ui->deleteMemberCB->addItem(member.Name());
    }
}

void AdministratorWindow::SetMembersTW() {
    ClearTable(this->ui->editMembersTW);

    QStringList headerLabels = { "Name", "ID", "Type", "Expiration", "Running Total" };
    this->ui->editMembersTW->setHorizontalHeaderLabels(headerLabels);

    for(size_t i = 0; i < m_MemberList.size(); i++) {
        this->ui->editMembersTW->insertRow(i);

        QString type;
        for(size_t col = 0; col < 5; col++) {
            QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: member name
             * 1: member id
             * 2: member type
             * 3: member expiration
             * 4: running total
             */
            switch(col) {
            // member name
            case 0:
                item->setText(m_MemberList[i].Name());
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

            // member id
            case 1:
                item->setText(QString::number(m_MemberList[i].Id()));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

            // member type
            case 2:
                type = m_MemberList[i].Type() ? "Executive" : "Regular";
                item->setText(type);
                break;

            // member expiration
            case 3:
                item->setText(m_MemberList[i].Expiration().DateString());
                break;

            // running total
            case 4:
                item->setText("$" + QString::number(m_MemberList[i].RunningTotal(), 'f', 2));
                break;
            }

            // align text to center
            item->setTextAlignment(Qt::AlignCenter);

            // add item to table
            this->ui->editMembersTW->setItem(i, col, item);
        }
        //resize column width to widest column
        this->ui->editMembersTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}





// items
void AdministratorWindow::SetConversionLE() {
    std::vector<Member> regularToExec, execToRegular;
    for(auto& member : m_MemberList) {
        if((member.RunningTotal() * 0.02) >= 55 && !member.Type()) {
            regularToExec.push_back(member);
        }
        else if((member.RunningTotal() * 0.02) < 55 && member.Type()) {
            execToRegular.push_back(member);
        }
    }

    SetConversionLE(this->ui->regularToExecConversionLW, this->ui->regToExecLabel, regularToExec);
    SetConversionLE(this->ui->execToRegularConvserionLW, this->ui->execToRegLabel, execToRegular);
}

void AdministratorWindow::SetConversionLE(QListWidget* listWidget, QLabel *label, const std::vector<Member>& conversions) {
    listWidget->clear();

    int i = 0;
    for(const auto& member : conversions) {
        listWidget->insertItem(i, member.Name());
        i++;
    }

    //sets distance label to display the total distance traveled and shows it to the user
    label->setText("Total Number of Suggested Conversions: " + QString::number(conversions.size()));
    label->show();

}





// general helpers
void AdministratorWindow::UpdateAll() {
    SetMembersCB();
    SetMembersTW();

    SetConversionLE();

    SetItemsCB();
    SetItemTotalsTW();
}

void AdministratorWindow::ClearTable(QTableWidget* tableWidget) {
    tableWidget->clear();
    int count = tableWidget->rowCount();
    while(count > 0) {
        tableWidget->removeRow(0);
        count = tableWidget->rowCount();
    }
}

// items
void AdministratorWindow::SetItemsCB() {
    m_pIdb = new InventoryManager(INVENTORY_PATH);
    m_Inventory = m_pIdb->AllItems();
    delete m_pIdb;

    this->ui->deleteItemCB->clear();
    for(size_t i = 0; i < m_Inventory.size(); i++) {
        this->ui->deleteItemCB->addItem(m_Inventory[i]->Name());
    }
}

void AdministratorWindow::SetItemTotalsTW() {
    m_Setting = true;

    m_pIdb = new InventoryManager(INVENTORY_PATH);
    //clear table
    ClearTable(this->ui->editItemsTW);

    //add header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Price");
    headerLabels.push_back("Item Quantity");
    headerLabels.push_back("Item Total");
    this->ui->editItemsTW->setHorizontalHeaderLabels(headerLabels);

    //grand total for all items
    float total = 0.0f;

    //local variable for m_Inventory to sort by item name
    ItemList inventory = m_Inventory;

    //sort by item name
    inventory.sort();

    for(size_t i = 0; i < inventory.size(); i++) {

        //insert row
        this->ui->editItemsTW->insertRow(i);

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
                itemName = inventory[i]->Name();
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                item->setText(itemName);
                break;

            // item price
            case 1:
                itemPrice = "$" + QString::number(inventory[i]->Price(), 'f', 2);
                item->setText(itemPrice);
                break;

            // item quantity
            case 2:
                itemQuantity = QString::number(inventory[i]->Quantity()) + " units";
                item->setText(itemQuantity);
                break;

            // item total
            case 3:
                itemTotal = "$" + QString::number(inventory[i]->Quantity() * inventory[i]->Price(), 'f', 2);
                item->setText(itemTotal);
                total += (inventory[i]->Quantity() * inventory[i]->Price());
            }

            //align text
            item->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->editItemsTW->setItem(i, col, item);
        }
    }

    this->ui->itemTotalLabel->setText("Grand total (w/o tax): $" + QString::number(total, 'f', 2));
    //resize column width to widest column
    this->ui->editItemsTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    m_Setting = false;
}






void AdministratorWindow::on_resetButton_clicked() {

    m_pDb = new DbManager(MEMBERS_PATH);
    m_pDb->ResetWithTextFile();
    delete m_pDb;

    m_pIdb = new InventoryManager(INVENTORY_PATH);
    m_pIdb->ResetWithTextFile();
    delete m_pIdb;

    UpdateAll();
}

