#include "dbmanager.h"

dbManager::dbManager(const QString& path) {
    m_Database = QSqlDatabase::addDatabase("QSQLITE");
    m_Database.setDatabaseName(path);

    if(!m_Database.open()) {
        qDebug() << "connection with database unsuccessful\n";
    }
    else {
        qDebug() << "connection with database successful\n";
    }
}

dbManager::~dbManager() {
    deleteAllMembers();
    m_Database.close();
    qDebug() << "database connection closed\n";
}

bool dbManager::addMember(const Member& member) {
    QString name = member.name();
    int id = member.id();
    bool type = member.type();
    QString expirationDate = member.expiration().dateString();
    double total = floor(member.runningTotal() * 100) / 100;
    QString receipt = member.receipt().receiptString();

    //logic for sales will be added later

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

    if(query.exec()) {
        qDebug().noquote().nospace() << name << " added successfully\n";
        return true;
    }
    qDebug() << "could not add member";
    return false;
}

bool dbManager::updateMember(const Member& member) {
    QString name = member.name();
    int id = member.id();
    bool type = member.type();
    QString expirationDate = member.expiration().dateString();

    //logic for sales will be added later

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("UPDATE MEMBERS SET NAME = :NAME, ID = :ID, TYPE = :TYPE, EXPIRATION = :EXPIRATION WHERE NAME = :NAME");
    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":EXPIRATION", expirationDate);

    if(query.exec()) {
        qDebug().noquote().nospace() << name << " updated successfully\n";
        return true;
    }
    qDebug() << "could not update member";
    return false;
}

void dbManager::deleteAllMembers() {
    QSqlQuery query("DELETE FROM MEMBERS");
}

bool dbManager::deleteMemberById(const int& id) {
    QSqlQuery query;

    query.prepare("DELETE FROM MEMBERS WHERE ID = ?");
    query.addBindValue(id);

    if(query.exec()) {
        return true;
    }
    qDebug() << "could not update member";
    return false;
}

unsigned dbManager::memberCount() const {
    QSqlQuery query("SELECT * FROM MEMBERS");

    unsigned count = 0;

    if(query.last()) {
        count = query.at() + 1;
    }

    return count;
}

std::vector<Member> dbManager::allMembers() const {
    std::vector<Member> memberList;

    QSqlQuery query("SELECT * FROM MEMBERS");

    while(query.next()) {
        memberList.push_back(memberFromRecord(query.record()));
    }

    return memberList;
}

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

Member dbManager::memberFromRecord(const QSqlRecord& record) const {
    QString name = record.value("NAME").toString();
    int id = record.value("ID").toInt();
    bool type = record.value("TYPE").toBool();
    QString dateString = record.value("EXPIRATION").toString();

    auto dates = dateString.split("/");

    int day, month, year;
    for(size_t i = 0; i < 3; i++) {
        switch(i) {
            case 0:
                day = (dates[0]).toInt();
                break;
            case 1:
                month = (dates[1]).toInt();
                break;
            case 2:
                year = (dates[2]).toInt();
                break;
            default:
                break;
        }
    }
    Date date(day, month, year);
    Member member(name, id, type, date);

    return member;
}

void dbManager::print() const {
    QSqlQuery query("SELECT * FROM MEMBERS");

    while(query.next()) {
        qDebug() << "member: ";
        for(size_t i = 0; i < NUM_COLUMNS; i++) {
            qDebug() << query.value(i).toString();
        }
        qDebug() << "";
    }
}

void dbManager::initialize() {
    deleteAllMembers();
    std::vector<Member> members;
    m_FileParser.read(members);
    for(const auto& member : members) {
        addMember(member);
    }
}
