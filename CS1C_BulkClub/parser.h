#ifndef PARSER_H
#define PARSER_H

#include "member.h"
#include "executivemember.h"
#include "itemlist.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <QFile>
#include <sstream>


#if __APPLE__ && TARGET_OS_MAC
    #define MEMBER_PATH "../../../../CS1C_BulkClub/warehouse_shoppers.txt"
#elif __linux__
    #define MEMBER_PATH "../CS1C_BulkClub/warehouse_shoppers.txt"
#else
    #define MEMBER_PATH = "..\\CS1D_FastFood\\warehouse_shoppers.txt"
#endif


#if __APPLE__ && TARGET_OS_MAC
    #define SALES_PATH "../../../../CS1C_BulkClub/day1.txt"
#elif __linux__
    #define SALES_PATH "../CS1C_BulkClub/day1.txt"
#else
    #define SALES_PATH = "..\\CS1D_FastFood\\day1.txt"
#endif

class Parser
{
private:
    bool readMembers(std::vector<Member>&);
    Date readDate(QString&);
    void addMember(std::vector<Member>&, const QString&, const int&, const bool&, const Date&);
    void debug(const std::vector<Member>&);
    bool readItems(std::vector<Member>&);
    bool addToReceipt(const QString&, const float&, const int&, const Date&, const int&, std::vector<Member>&);
public:
    Parser();
    bool read(std::vector<Member>&);
};

#endif // PARSER_H
