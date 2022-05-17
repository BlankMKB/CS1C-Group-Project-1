#ifndef PATHS_H
#define PATHS_H

#ifdef USE_PATHS

#include <QDialog>

//define member path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define MEMBERS_PATH "../../../../CS1C_BulkClub/members.db"
#elif __linux__
    #define MEMBERS_PATH "../CS1C_BulkClub/members.db"
#else
    #define MEMBERS_PATH "..\\CS1C_BulkClub\\members.db"
#endif

//define sales path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define INVENTORY_PATH "../../../../CS1C_BulkClub/inventory.db"
#elif __linux__
    #define INVENTORY_PATH "../CS1C_BulkClub/inventory.db"
#else
    #define INVENTORY_PATH "..\\CS1C_BulkClub\\inventory.db"
 #endif



//define member path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define MEMBER_PATH "../../../../CS1C_BulkClub/warehouse_shoppers.txt"
#elif __linux__
    #define MEMBER_PATH "../CS1C_BulkClub/warehouse_shoppers.txt"
#else
    #define MEMBER_PATH "..\\CS1C_BulkClub\\warehouse_shoppers.txt"
#endif

//define sales path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define SALES_PATH "../../../../CS1C_BulkClub/sales.txt"
#elif __linux__
    #define SALES_PATH "../CS1C_BulkClub/sales.txt"
#else
    #define SALES_PATH "..\\CS1C_BulkClub\\sales.txt"
#endif

#define DEBUG qDebug().noquote().nospace()

#endif

#endif // PATHS_H
