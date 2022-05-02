#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <cmath>
#include "member.h"
#include "parser.h"
#define NUM_COLUMNS 6

class dbManager {
private:
    QSqlDatabase m_Database; /*!< \var database object */
    Parser m_FileParser; /*!< \var parser object */

private:
    /*!
     * \brief helper function that parses receipt from receipt string
     * \return receipt: Receipt
     */
    Receipt parseReceipt(const QString&) const;

    /*!
     * \brief helper function that parses date from date string
     * \return date: Date
     */
    Date parseDate(const QString&) const;

    /*!
     * \brief helper function that builds and returns member from the SQL database
     * \return member: Member
     */
    Member memberFromRecord(const QSqlRecord&) const;

    /*!
     * \brief helper function that builds and returns receipt from the SQL database
     * \return receipt: Receipt
     */
    Receipt receiptFromRecord(const QSqlRecord&) const;

    /*!
     * \brief checks if database is empty
     * \return true if empty, false otherwise
     */
    bool empty() const;

public:
    /*!
     * \brief overloaded constructor
     * \param path: QString
     */
    dbManager(const QString&);

    /*!
     * \brief destructor
     */
    ~dbManager();

    /*!
     * \brief initializes database
     * \return true if initialized correctly, false otherwise
     */
    bool initialize();

    /*!
     * \brief returns member by specified id
     * \return member: Member
     */
    Member memberById(const int&) const;

    /*!
     * \brief returns a vector of members
     * \return memberList: std::vector<Member>
     */
    std::vector<Member> allMembers() const;

    /*!
     * \brief returns a vector of pairs of receipts
     * \paragraph the vector of pairs is in the format: [Member, Receipt] and is in no particular order.
     *            This function returns a pair mainly for ease of access to all of the receipts.
     * \return receipts: std::vector<std::pair<Member, Receipt>>
     */
    std::vector<std::pair<Member, Receipt>> allReceipts() const;

    /*!
     * \brief returns how many members are in the database
     * \return count: unsigned
     */
    unsigned memberCount() const;

    /*!
     * \brief adds member into database
     * \return true if added correctly, false otherwise
     */
    bool addMember(const Member&);

    /*!
     * \brief updates member in database
     * \return true if updated correctly, false otherwise
     */
    bool updateMember(const Member&);
    /*!
     * \brief deletes member by id from database
     * \return true if deleted correctly, false otherwise
     */
    bool deleteMemberById(const int&);

    /*!
     * \brief deletes all members from the database
     */
    void deleteAllMembers();

    /*!
     * \brief for debug purposes: prints all member data
     */
    void print() const;
};

#endif // DBMANAGER_H
