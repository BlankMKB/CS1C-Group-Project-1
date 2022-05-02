#ifndef PARSER_H
#define PARSER_H

#include "member.h"
#include "executivemember.h"
#include "itemlist.h"

#include <iostream>
#include <limits>
#include <QFile>


//define member path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define MEMBER_PATH "../../../../CS1C_BulkClub/warehouse_shoppers.txt"
#elif __linux__
    #define MEMBER_PATH "../CS1C_BulkClub/warehouse_shoppers.txt"
#else
    #define MEMBER_PATH = "..\\CS1C_BulkClub\\warehouse_shoppers.txt"
#endif

//define sales path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define SALES_PATH "../../../../CS1C_BulkClub/sales.txt"
#elif __linux__
    #define SALES_PATH "../CS1C_BulkClub/sales.txt"
#else
    #define SALES_PATH = "..\\CS1C_BulkClub\\sales.txt"
#endif

class Parser {
private:
    ItemList m_Inventory; /*!< \var inventory itemlist */

private:
    /*!
     * \brief helper function that reads all the members and stores it into a vector of members
     * \return true if parsed correctly, false otherwise
     */
    bool readMembers(std::vector<Member>&);

    /*!
     * \brief helper function that reads all the items and stores it into the vector of members
     * \return true if parsed correctly, false otherwise
     */
    bool readItems(std::vector<Member>&);

    /*!
     * \brief helper function that parses and stores date string into date object
     * \return date: Date
     */
    Date readDate(QString&);

    /*!
     * \brief helper function that constructs member object and adds it to the vector of members
     */
    void addMember(std::vector<Member>&, const QString&, const int&, const bool&, const Date&);

    /*!
     * \brief helper function that constructs Item object and adds it to the vector of member's receipts
     * \return true if added correctly, false otherwise
     */
    bool addToReceipt(const QString&, const float&, const int&, const Date&, const int&, std::vector<Member>&);

    /*!
     * \brief rounds decimal to 2 places
     * \param number: float
     */
    void round(float&) const;

public:
    /*!
     * \brief default constructor
     */
    Parser();

    /*!
     * \brief reads the entire file and parses it into a vector of members
     * \return true if everything parsed correctly, false otherwise
     */
    bool read(std::vector<Member>&);

    /*!
     * \brief returns an inventory of items
     * \return inventory: std::vector<Item*>
     */
    ItemList inventory() const;

    /*!
     * \brief for debugging purposes: prints member information
     */
    void debug(const std::vector<Member>&);
};

#endif // PARSER_H
