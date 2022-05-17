#include "inventorymanager.h"

//constructor
InventoryManager::InventoryManager(const QString& path) {
    //add database to QT
    m_Database = QSqlDatabase::addDatabase("QSQLITE");
    //set database path
    m_Database.setDatabaseName(path);

    //check if database opened successfully
    if(!m_Database.open()) {
        qDebug() << "connection with database unsuccessful\n";
    }
    else {
        qDebug() << "connection with database successful\n";
    }
}

//destructor
InventoryManager::~InventoryManager() {
    //close database
    m_Database.close();
    qDebug() << "database connection closed\n";
}





//initializes database with text file
bool InventoryManager::InitializeInventoryDB() {
    if(Empty()) {
        std::vector<Member> x;
        m_FileParser.Read(x);
        ItemList inventory = m_FileParser.Inventory();
        for(const auto& item : inventory.itemList()) {
            AddItem(item);
        }
    }
    //everything initialized correctly
    return true;
}

//get item by name
Item InventoryManager::ItemByName(const QString& name) const {
    Item item;

    QSqlQuery query;
    query.prepare("SELECT * FROM INVENTORY WHERE NAME = ?");
    query.addBindValue(name);
    query.exec();
    query.next();
    auto record = query.record();

    item = ItemFromRecord(record);

    return item;
}

//get a vector of items
ItemList InventoryManager::AllItems() const {
    ItemList inventory;

    QSqlQuery query("SELECT * FROM INVENTORY");

    while(query.next()) {
        Item* temp = new Item(ItemFromRecord(query.record()));
        inventory.Insert(temp);
    }

    return inventory;
}

//return item count
size_t InventoryManager::ItemCount() const {
    QSqlQuery query("SELECT * FROM INVENTORY");

    size_t count = 0;

    if(query.last()) {
        count = query.at() + 1;
    }

    return count;
}

// empty
bool InventoryManager::Empty() const {
    return ItemCount() == 0;
}





//add item to database
bool InventoryManager::AddItem(const Item* item) {
    //parse item object
    const QString name = item->Name();
    const float price = item->Price();
    const int quantity = item->Quantity();

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("INSERT INTO INVENTORY (name, price, quantity) VALUES (:NAME, :PRICE, :QUANTITY)");

    //bind item information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":PRICE", price);
    query.bindValue(":QUANTITY", quantity);

    //check to see if item was added successfully
    if(query.exec()) {
        qDebug().noquote().nospace() << name << " added successfully\n";
        return true;
    }

    qDebug() << "could not add item";
    return false;
}

//update item in database
bool InventoryManager::UpdateItem(const Item& item) {
    //parse item object
    const QString name = item.Name();
    const float price = item.Price();
    const int quantity = item.Quantity();

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("UPDATE INVENTORY SET NAME = :NAME, PRICE = :PRICE, QUANTITY = :QUANTITY WHERE NAME = :NAME");
    //bind item information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":PRICE", price);
    query.bindValue(":QUANTITY", quantity);

    //check to see if item was updated successfully
    if(query.exec()) {
        qDebug().noquote().nospace() << name << " updated successfully\n";
        return true;
    }
    qDebug() << "could not update item";
    return false;
}

//delete item by id
bool InventoryManager::DeleteItemByName(const QString& name) {
    QSqlQuery query;

    query.prepare("DELETE FROM INVENTORY WHERE NAME = ?");
    query.addBindValue(name);

    if(query.exec()) {
        return true;
    }
    qDebug() << "could not delete item";
    return false;
}

//delete all item
void InventoryManager::DeleteAllItems() {
    QSqlQuery query("DELETE FROM INVENTORY");
}

//for debug purposes
void InventoryManager::PrintInventoryDB() const {
    QSqlQuery query("SELECT * FROM INVENTORY");

    while(query.next()) {
        qDebug() << "item: ";
        for(size_t i = 0; i < NUM_COLUMNS; i++) {
            QString value = query.value(i).toString();

            qDebug().noquote().nospace() << value;
        }
        qDebug() << "";
    }
}





// reset with text file
void InventoryManager::ResetWithTextFile() {
    DeleteAllItems();
    InitializeInventoryDB();
}






// item from record
Item InventoryManager::ItemFromRecord(const QSqlRecord& record) const {
    //assign item information from SQL
    const QString name = record.value("NAME").toString();
    const float price = record.value("PRICE").toFloat();
    const int quantity = record.value("QUANTITY").toInt();

    Item item(name, price, quantity);

    return item;
}
