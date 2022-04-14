#include "dbmanager.h"

dbManager::dbManager(const QString& path) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path);

    if(!database.open()) {
        qDebug() << "connection with database unsuccessful\n";
    }
    else {
        qDebug() << "connection with database unsuccessful\n";
    }
}

dbManager::~dbManager() {
    database.close();
    qDebug() << "database connection closed\n";
}

bool dbManager::addMember(const Member& member) {
    QString name = member.name();
    int id = member.id();
    bool type = member.type();
    Date expiration = member.expiration();

    //logic for sales will be added later

    //create an insert query with the perameters to load the table
    QSqlQuery query;
    query.prepare("INSERT INTO MEMBERS (name, id, type, expiration) VALUES (:NAME, :ID, :TYPE, :EXPIRATION)");

    //bind member information to their respective columns
    query.bindValue(":NAME", name);
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    //query.bindValue(":EXPIRATION", expiration);


}
