#include "memberwindow.h"
#include "ui_memberwindow.h"

MemberWindow::MemberWindow(QWidget *parent, Member* member) :
    QDialog(parent),
    ui(new Ui::MemberWindow)
{
    ui->setupUi(this);

    m_CurrMember = *member;

    m_pIdb = new InventoryManager(INVENTORY_PATH);
    m_Inventory = m_pIdb->AllItems();
    delete m_pIdb;

    SetItemCB();
    this->ui->cartTotalLabel->hide();


}

MemberWindow::~MemberWindow()
{
    delete ui;
}

void MemberWindow::on_addToCartButton_clicked() {
    QString itemName = this->ui->cartItemCB->currentText();
    int itemQuantity = this->ui->quantitySB->value();

    if(itemQuantity > 0) {
        AddToTableWidget(itemName, itemQuantity);
    }
    this->ui->quantitySB->setValue(0);
}

void MemberWindow::SetItemCB() {
    for(size_t i = 0; i < m_Inventory.size(); i++) {
        this->ui->cartItemCB->addItem(m_Inventory[i]->Name());
    }
}

void MemberWindow::AddToTableWidget(const QString& itemName, const int& itemQuantity) {
    const Item* p_Item = nullptr;
    for(size_t i = 0; i < m_Inventory.size(); i++) {
        if(m_Inventory[i]->Name() == itemName) {
            p_Item = m_Inventory[i];
            Item* tempItem = new Item(p_Item->Name(), p_Item->Price(), itemQuantity);
            DEBUG << "Item: " << tempItem->Name() << ". Quantity " << tempItem->Quantity() << " added";
            m_Cart.InsertInventory(tempItem);
            break;
        }
    }

    //total amount before tax
    float total = 0.0f;
    bool exists = false;

    for(int i = 0; i < this->ui->cartTW->rowCount(); i++) {
        if(this->ui->cartTW->item(i, 0)->text() == itemName) {
            this->ui->cartTW->item(i, 2)->setText(QString::number(this->ui->cartTW->item(i, 2)->text().toInt() + itemQuantity));
            this->ui->cartTW->item(i, 3)->setText("$" + QString::number(this->ui->cartTW->item(i, 2)->text().toInt() * this->ui->cartTW->item(i, 1)->text().toFloat()));
            exists = true;
            break;
        }
    }

    if(!exists) {
        this->ui->cartTW->insertRow(this->ui->cartTW->rowCount());

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
                item->setText(p_Item->Name());
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

                // item price
            case 1:
                item->setText("$" + QString::number(p_Item->Price(), 'f', 2));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

                // item quantity
            case 2:
                item->setText(QString::number(itemQuantity));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

                // item total
            case 3:
                item->setText("$" + QString::number(p_Item->Price() * itemQuantity, 'f', 2));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;
            }

            //align text
            item->setTextAlignment(Qt::AlignCenter);

            //add item to table
            this->ui->cartTW->setItem(this->ui->cartTW->rowCount() - 1, col, item);
        }
    }

    for(size_t i = 0; i < m_Cart.size(); i++) {
        total += m_Cart[i]->Price() * m_Cart[i]->Quantity();
    }

    //resize column width to widest column
    this->ui->cartTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //clear total revenue label
    this->ui->cartTotalLabel->clear();

    //calculate total with sales
    float salesTotal = total + (total * SALES_TAX);

    //set total revenue string
    QString revenue = "Total (w/ tax): $" + QString::number(salesTotal, 'f', 2);

    //set revenue text to revenue label
    this->ui->cartTotalLabel->setText(revenue);
    if(this->ui->cartTotalLabel->isVisible()) {
        return;
    }
    this->ui->cartTotalLabel->show();
}

void MemberWindow::on_purchaseButton_clicked() {

    Date date(5, 18, 2022);

    for(size_t i = 0; i < m_Cart.size(); i++) {
        m_CurrMember.Purchase(m_Cart[i], date);
        m_Inventory.InsertInventory(m_Cart[i]);
    }

    m_pIdb = new InventoryManager(INVENTORY_PATH);
    for(size_t i = 0; i < m_Inventory.size(); i++) {
        m_pIdb->UpdateItem(m_Inventory[i]);
    }
    delete m_pIdb;


    m_pDb = new DbManager(MEMBERS_PATH);
    m_pDb->UpdateMember(m_CurrMember);
    delete m_pDb;

    ClearTable(this->ui->cartTW);
    this->ui->cartTotalLabel->hide();

}
void MemberWindow::ClearTable(QTableWidget* tableWidget) {
    tableWidget->clear();
    int count = tableWidget->rowCount();
    while(count > 0) {
        tableWidget->removeRow(0);
        count = tableWidget->rowCount();
    }
    SetHeaderLabels();
}

void MemberWindow::SetHeaderLabels() {
    //assign header labels
    QStringList headerLabels;
    headerLabels.push_back("Item Name");
    headerLabels.push_back("Item Price");
    headerLabels.push_back("Item Quantity");
    headerLabels.push_back("Item Total");
    this->ui->cartTW->setHorizontalHeaderLabels(headerLabels);
}