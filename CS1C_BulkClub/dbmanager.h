#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <unordered_map>
#include "member.h"
//#include "parser.h"

class dbManager {
private:
    QSqlDatabase database;
    //parser fileParser;



public:
    dbManager(const QString&);

    ~dbManager();

    bool addMember(const Member&);

    void deleteAllMembers();

    int getMemberCount() const;

    Member getMemberByName(const QString&) const;

    Member getMemberFromRecord(const QSqlRecord&) const;

    bool updateMember(const Member& college);

    void resetWithFile();
};

#endif // DBMANAGER_H
