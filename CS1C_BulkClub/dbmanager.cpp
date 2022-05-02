#include "dbmanager.h"

//==========================================PRIVATE MEMBER FUNCTIONS==========================================

//parse date string into date object
Date dbManager::parseDate(const QString& line) const {
    //split date format: [month]/[day]/[year]
    auto dates = line.split("/");

    //temp int day month year
    int day, month, year;

    //iterate through 3 times (dd/mm/yyyy)
    for(size_t i = 0; i < 3; i++) {
        /* switch case format
         * 0: month
         * 1: day
         * 2: year
         */
        switch(i) {
        // day
        case 0:
            month = (dates[0]).toInt();
            break;
        // month
        case 1:
            day = (dates[1]).toInt();
            break;
        // year
        case 2:
            year = (dates[2]).toInt();
            break;
        default:
            break;
        }
    }

    //create date object
    Date date(month, day, year);

    return date;
}

//parse receipt string into date object
Receipt dbManager::parseReceipt(const QString& line) const {
    //receipt object
    Receipt receipt;

    //if receipt is empty, return empty receipt
    if(line == "") {
        return receipt;
    }

    //split receipts by day using '#' flag
    auto fullReceipt = line.split("#");

    //for each day
    for(auto& receiptDay : fullReceipt) {
        Item* item;
        QString itemName;
        float itemPrice;
        int itemQuantity;
        int count = 1;

        //split day by items
        auto items = receiptDay.split(", ");

        //ignore extraneous split ""
        if(items[0] == "") {
            continue;
        }

        //first item is the purchase date
        Date date(parseDate(items[0]));

        //for all of the items
        for(qsizetype i = 1; i < items.size(); i++) {
            /* switch case format
             * 1: item name
             * 2: item price
             * 3: item quantity
             * 4: create item and add to receipt object
             */
            switch(i % 5) {
            // item name
            case 1:
                itemName = items[count];
                count++;
                break;
            // item price
            case 2:
                itemPrice = items[count].toFloat();
                count++;
                break;
            // item quantity
            case 3:
                itemQuantity = items[count].toInt();
                count++;
                break;
            // create item and add to receipt
            case 4:
                //create item
                item = new Item(itemName, itemPrice, itemQuantity);
                //add to receipt
                receipt.add(date, item);
                break;
            default:
                itemName = "";
                itemPrice = 0;
                itemQuantity = 0;
                break;
            }
        }
    }

    return receipt;
}

//get member from record into member object
Member dbManager::memberFromRecord(const QSqlRecord& record) const {
    //assign member information from SQL
    const QString name = record.value("NAME").toString();
    const int id = record.value("ID").toInt();
    const bool type = record.value("TYPE").toBool();
    const QString dateString = record.value("EXPIRATION").toString();
    const QString receiptString = record.value("RECEIPT").toString();

    const Date date = parseDate(dateString);
    const Receipt receipt = parseReceipt(receiptString);

    Member member(name, id, type, date);
    member.setReceipt(receipt);

    return member;
}

//get receipt from record into receipt object
Receipt dbManager::receiptFromRecord(const QSqlRecord& record) const {
    const QString receiptString = record.value("RECEIPT").toString();

    Receipt receipt = parseReceipt(receiptString);

    return receipt;
}

//empty
bool dbManager::empty() const {
    return this->memberCount() == 0;
}

//=============================================================================================================


//===========================================PUBLIC MEMBER FUNCTIONS===========================================

//constructor
dbManager::dbManager(const QString& path) {
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
dbManager::~dbManager() {
    //close database
    //deleteAllMembers();
    m_Database.close();
    qDebug() << "database connection closed\n";
}

//initializes database with text file
bool dbManager::initialize() {
    if(this->empty()) {
        std::vector<Member> members;
        m_FileParser.read(members);
        for(const auto& member : members) {
            if(!addMember(member)) {
                return false;
            }
        }
    }
    //everything initialized correctly
    return true;
}

//get member by id
Member dbManager::memberById(const int& id) const {
    Member member;

    QSqlQuery query;
    query.prepare("SELECT * FROM MEMBERS WHERE ID = ?");
    query.addBindValue(id);
    query.exec();
    query.next();
    auto record = query.record();

    member = memberFromRecord(record);

    return member;
}

//get a vector of members
std::vector<Member> dbManager::allMembers() const {
    std::vector<Member> memberList;

    QSqlQuery query("SELECT * FROM MEMBERS");

    while(query.next()) {
        memberList.push_back(memberFromRecord(query.record()));
    }

    return memberList;
}

//get a vector of [Member, Receipt] pairs
std::vector<std::pair<Member, Receipt>> dbManager::allReceipts() const {
    std::vector<std::pair<Member, Receipt>> receipts;
    QSqlQuery query("SELECT * FROM MEMBERS");

    while(query.next()) {
        receipts.push_back(std::make_pair(memberFromRecord(query.record()), receiptFromRecord(query.record())));

    }

    return receipts;
}

//return member count
unsigned dbManager::memberCount() const {
    QSqlQuery query("SELECT * FROM MEMBERS");

    unsigned count = 0;

    if(query.last()) {
        count = query.at() + 1;
    }

    return count;
}

//add member to database
bool dbManager::addMember(const Member& member) {
    //parse member object
    const QString name = member.name();
    const int id = member.id();
    const bool type = member.type();
    const QString expirationDate = member.expiration().dateString();
    const double total = member.runningTotal();
    const QString receipt = member.receipt().receiptString();

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("INSERT INTO MEMBERS (name, id, type, expiration, total, receipt) VALUES (:NAME, :ID, :TYPE, :EXPIRATION, :TOTAL, :RECEIPT)");

    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":EXPIRATION", expirationDate);
    query.bindValue(":TOTAL", total);
    query.bindValue(":RECEIPT", receipt);

    //check to see if member was added successfully
    if(query.exec()) {
        qDebug().noquote().nospace() << name << " added successfully\n";
        return true;
    }

    qDebug() << "could not add member";
    return false;
}

//update member in database
bool dbManager::updateMember(const Member& member) {
    //parse member object
    const QString name = member.name();
    const int id = member.id();
    const bool type = member.type();
    const QString expirationDate = member.expiration().dateString();
    const double total = member.runningTotal();
    const QString receipt = member.receipt().receiptString();


    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("UPDATE MEMBERS SET NAME = :NAME, ID = :ID, TYPE = :TYPE, EXPIRATION = :EXPIRATION, TOTAL = :TOTAL, RECEIPT = :RECEIPT WHERE NAME = :NAME");
    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":EXPIRATION", expirationDate);
    query.bindValue(":TOTAL", total);
    query.bindValue(":RECEIPT", receipt);

    //check to see if member was updated successfully
    if(query.exec()) {
        qDebug().noquote().nospace() << name << " updated successfully\n";
        return true;
    }
    qDebug() << "could not update member";
    return false;
}

//delete member by id
bool dbManager::deleteMemberById(const int& id) {
    QSqlQuery query;

    query.prepare("DELETE FROM MEMBERS WHERE ID = ?");
    query.addBindValue(id);

    if(query.exec()) {
        return true;
    }
    qDebug() << "could not delete member";
    return false;
}

//delete all members
void dbManager::deleteAllMembers() {
    QSqlQuery query("DELETE FROM MEMBERS");
}

//for debug purposes
void dbManager::print() const {
    QSqlQuery query("SELECT * FROM MEMBERS");

    while(query.next()) {
        qDebug() << "member: ";
        for(size_t i = 0; i < NUM_COLUMNS; i++) {
            QString value = query.value(i).toString();
            if(value == "1") {
                value = "Executive";
            }
            else if(value == "0") {
                value = "Regular";
            }

            qDebug().noquote().nospace() << value;
        }
        qDebug() << "";
    }
}

//=============================================================================================================
