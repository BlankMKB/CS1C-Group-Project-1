#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <unordered_map>
#include <cmath>
#include "member.h"
#include "parser.h"
#define NUM_COLUMNS 6

class dbManager {
private:
    QSqlDatabase m_Database;
    Parser m_FileParser;

    Receipt parseReceipt(QString&) const;
    Date parseDate(QString&) const;
    Member memberFromRecord(const QSqlRecord&) const;
    Receipt receiptFromRecord(const QSqlRecord&) const;

public:
    dbManager(const QString&);

    ~dbManager();

    bool addMember(const Member&);

    bool deleteMemberById(const int&);

    bool updateMember(const Member&);

    void deleteAllMembers();

    unsigned memberCount() const;

    Member memberById(const int&) const;

    std::vector<Member> allMembers() const;

    std::vector<std::pair<Member, Receipt>> allReceipts() const;

    void print() const;

    void initialize();

    //void print(const int&) const;
};

#endif // DBMANAGER_H
