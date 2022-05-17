#ifndef PARSER_H
#define PARSER_H

#include "member.h"
#include "executivemember.h"
#include "itemlist.h"

#include <iostream>
#include <limits>
#include <QFile>

#define USE_PATHS
#include "paths.h"



/*!
 * \class Parser
 * \brief The Parser Class
 * \details This class parses both the member and sales files.
 * \paragraph This class only has three public functions: Read(), Inventory(),
 * and DebugParser(). Read() reads both the member and sales files.
 * Inventory() returns a list of all items in an "inventory" (no
 * duplicate items in the item list). DebugParser() prints the
 * vector of members and the items that it parsed.
 * \note This class has a defaulted default constructor and destructor.
 * \note This class deletes the copy constructor and operator=() function.
 *
 */
class Parser {
// accessors
public:
    /*!
     * \fn Read(std::vector<Member>&)
     * \brief Reads the entire file and parses it into a vector of members
     * \param members: std::vector<Member>
     * \return true if everything parsed correctly, false otherwise
     */
    bool Read(std::vector<Member>& members);

    /*!
     * \fn Inventory()
     * \brief Returns an inventory of items
     * \return inventory: std::vector<Item*>
     */
    ItemList Inventory() const;

// debug
public:
    /*!
     * \fn DebugParser(const std::vector<Member>&)
     * \brief for debugging purposes: prints member information
     * \param members: std::vector<Member>
     */
    void DebugParser(const std::vector<Member>& members);

// defaulted functions
public:
    /*!
     * \fn Parser()
     * \brief Default constructor
     */
    Parser() = default;

    /*!
     * \fn ~Parser()
     * \brief Default destructor
     */
    ~Parser() = default;

// deleted functions
public:
    /*!
     * \fn Parser(const Parser&)
     * \brief Deleted copy constructor
     * \param other
     */
    Parser(const Parser& other) = delete;

    /*!
     * \fn operator=(const Parser&)
     * \brief Deleted operator=
     * \param other
     * \return parser: Parser
     */
    Parser& operator=(const Parser& other) = delete;
// helper functions
private:
    /*!
     * \fn ReadMembers(std::vector<Member>&)
     * \brief Helper function that reads all the members and stores it into a vector of members
     * \param members: std::vector<Member>
     * \return true if parsed correctly, false otherwise
     */
    bool ReadMembers(std::vector<Member>& members);

    /*!
     * \fn ReadItems(std::vector<Member>&)
     * \brief Helper function that reads all the items and stores it into the vector of members
     * \param members: std::vector<Member>
     * \return true if parsed correctly, false otherwise
     */
    bool ReadItems(std::vector<Member>& members);

    /*!
     * \fn ReadDate(QString&)
     * \brief Helper function that parses and stores date string into date object
     * \param line: QString
     * \return date: Date
     */
    Date ReadDate(QString& line);

    /*!
     * \fn AddMember(std::vector<Member>&, const QString&, const int& const bool& const Date&)
     * \brief Helper function that constructs member object and adds it to the vector of members
     * \param members: std::vector<Member>
     * \param name: QString
     * \param id: int
     * \param type: bool
     * \param expiration: Date
     */
    void AddMember(std::vector<Member>& members, const QString& name, const int& id, const bool& type, const Date& expiration);

    /*!
     * \fn AddToReceipt(std::vector<Member>&, const Qstring&, const float& const int& const Date& const int&)
     * \brief Helper function that constructs Item object and adds it to the vector of member's receipts
     * \param members: std::vector<Member>
     * \param name: QString
     * \param price: float
     * \param quantity: int
     * \param date: Date
     * \param id: int
     * \return true if added correctly, false otherwise
     */
    bool AddToReceipt(std::vector<Member>& members, const QString& name, const float& price, const int& quantity, const Date& date, const int& id);

// variables
private:
    ItemList m_Inventory; /*!< \var inventory itemlist */

};

#endif // PARSER_H
