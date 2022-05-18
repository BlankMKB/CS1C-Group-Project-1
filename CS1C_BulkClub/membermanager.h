#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>

#include <cmath>

#include "member.h"
#include "parser.h"

#define USE_PATHS
#define USE_DEBUG
#include "defines.h"
#define NUM_MEMBER_COLUMNS 6


/*!
 * \class MemberManager
 * \brief The MemberManager Class
 * \details This class stores member information into a database.
 * \paragraph The database, by default, is set to store persistent changes.
 * In order to reset the database, use the function ResetWithTextFile().
 * You must use the overloaded constructor with a specified path.
 * Main initializes the member database if and only if the database is empty.
 * To manually reset the database, call DeleteAllMembers() then InitializeMembersDB().
 * \note This class deletes the default copy constructor and operator=() function.
 */
class MemberManager {
// constructors
public:
    /*!
     * \fn MemberManager(const QString&)
     * \brief Overloaded constructor
     * \param path: QString
     */
    MemberManager(const QString& path);

    /*!
     * \fn ~MemberManager()
     * \brief Defualt destructor
     */
    ~MemberManager();

// database accessors
public:
    /*!
     * \fn InitializeMemberDB()
     * \brief Initializes database
     * \return true if initialized correctly, false otherwise
     */
    bool InitializeMemberDB();

    /*!
     * \fn MemberById(const int&)
     * \brief Returns member by specified id
     * \param id: int
     * \return member: Member
     */
    Member MemberById(const int& id) const;

    /*!
     * \fn AllMembers()
     * \brief Returns a vector of members
     * \return memberList: std::vector<Member>
     */
    std::vector<Member> AllMembers() const;

    /*!
     * \fn AllReceipts()
     * \brief Returns a vector of pairs of receipts
     * \details The vector of pairs is in the format: [Member, Receipt] and is in no particular order.
     *              This function returns a pair mainly for ease of access to all of the receipts.
     * \return receipts: std::vector<std::pair<Member, Receipt>>
     */
    std::vector<std::pair<Member, Receipt>> AllReceipts() const;

    /*!
     * \fn MemberCount()
     * \brief Returns how many members are in the database
     * \return count: size_t
     */
    size_t MemberCount() const;

    /*!
     * \fn Empty()
     * \brief checks if database is empty
     * \return true if empty, false otherwise
     */
    bool Empty() const;

// mutators
public:
    /*!
     * \fn AddMember(const Member&)
     * \brief Adds member into database
     * \param member: Member
     * \return true if added correctly, false otherwise
     */
    bool AddMember(const Member& member);

    /*!
     * \fn UpdateMember(Member&)
     * \brief Updates member in database
     * \param member: Member
     * \return true if updated correctly, false otherwise
     */
    bool UpdateMember(const Member& member);

    /*! \fn DeleteMemberById(const int&)
     * \brief Deletes member by id from database
     * \param id: int
     * \return true if deleted correctly, false otherwise
     */
    bool DeleteMemberById(const int& id);

    /*!
     * \fn DeleteAllMembers()
     * \brief deletes all members from the database
     */
    void DeleteAllMembers();

// debug
public:
    /*!
     * \fn PrintMemberDB()
     * \brief for debug purposes: prints all member data
     */
    void PrintMemberDB() const;

    /*!
     * \fn ResetWithTextFile()
     * \brief reset with text file
     */
    void ResetWithTextFile();

// deleted functions
public:
    /*!
     * \fn MemberManager()
     * \brief Deleted default constructor
     */
    MemberManager() = delete;

    /*!
     * \fn operator=(const MemberManager&)
     * \brief Deleted operator=
     * \param other: MemberManager
     * \return MemberManager
     */
    MemberManager& operator=(const MemberManager& other) = delete;

// helper functions
private:
    /*!
     * \fn ParseReceipt(Member&, const QString&)
     * \brief Helper function that parses receipt from receipt string
     * \param member: Member
     * \param line: QString
     * \return receipt: Receipt
     */
    Receipt ParseReceipt(Member& member, const QString& line) const;

    /*!
     * \fn MemberFromRecord(const QSqlRecord&)
     * \param record: QSqlRecord
     * \brief Helper function that builds and returns member from the SQL database
     * \return member: Member
     */
    Member MemberFromRecord(const QSqlRecord& record) const;

    /*!
     * \fn ReceiptFromRecord(const QSqlRecord&)
     * \brief Helper function that builds and returns receipt from the SQL database
     * \param record: QSqlRecord
     * \return receipt: Receipt
     */
    Receipt ReceiptFromRecord(const QSqlRecord& record) const;

// variables
private:
    QSqlDatabase m_Database;    /*!< \var database object: QSqlDatabase */
    Parser       m_FileParser;  /*!< \var parser object: Parser */
};

#endif // MemberManager_H
