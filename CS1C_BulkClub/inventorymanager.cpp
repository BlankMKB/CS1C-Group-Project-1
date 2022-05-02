#include "inventorymanager.h"

//==========================================PRIVATE MEMBER FUNCTIONS==========================================

Item InventoryManager::itemFromRecord(const QSqlRecord& record) const {
    //assign item information from SQL
    const QString name = record.value("NAME").toString();
    const int price = record.value("PRICE").toFloat();
    const int quantity = record.value("QUANTITY").toInt();

    Item item(name, price, quantity);

    return item;
}

//empty
bool InventoryManager::empty() const {
    return this->itemCount() == 0;
}


//=============================================================================================================


//===========================================PUBLIC MEMBER FUNCTIONS===========================================

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
bool InventoryManager::initialize() {
    if(this->empty()) {
        std::vector<Member> x;
        m_FileParser.read(x);
        ItemList inventory = m_FileParser.inventory();
        for(const auto& item : inventory.itemList()) {
            addItem(item);
        }
    }
    //everything initialized correctly
    return true;
}

//get item by name
Item InventoryManager::itemByName(const QString& name) const {
    Item item;

    QSqlQuery query;
    query.prepare("SELECT * FROM INVENTORY WHERE NAME = ?");
    query.addBindValue(name);
    query.exec();
    query.next();
    auto record = query.record();

    item = itemFromRecord(record);

    return item;
}

//get a vector of items
ItemList InventoryManager::allItems() const {
    ItemList inventory;

    QSqlQuery query("SELECT * FROM INVENTORY");

    while(query.next()) {
        Item* temp = new Item(itemFromRecord(query.record()));
        inventory.insert(temp);
    }

    return inventory;
}

//return item count
unsigned InventoryManager::itemCount() const {
    QSqlQuery query("SELECT * FROM INVENTORY");

    unsigned count = 0;

    if(query.last()) {
        count = query.at() + 1;
    }

    return count;
}

//add item to database
bool InventoryManager::addItem(const Item* item) {
    //parse item object
    const QString name = item->name();
    const float price = item->price();
    const int quantity = item->quantity();

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
bool InventoryManager::updateItem(const Item& item) {
    //parse item object
    const QString name = item.name();
    const float price = item.price();
    const int quantity = item.quantity();

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
bool InventoryManager::deleteItemByName(const QString& name) {
    QSqlQuery query;

    query.prepare("DELETE FROM INVENTORY WHERE ID = ?");
    query.addBindValue(name);

    if(query.exec()) {
        return true;
    }
    qDebug() << "could not delete item";
    return false;
}

//delete all item
void InventoryManager::deleteAllItems() {
    QSqlQuery query("DELETE FROM INVENTORY");
}

//for debug purposes
void InventoryManager::print() const {
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

//=============================================================================================================
