#ifndef DEFINES_H
#define DEFINES_H

// path macros
#define USE_PATHS
#ifdef USE_PATHS

#include <QDialog>

#if __APPLE__ && TARGET_OS_MAC
    #define MEMBERS_PATH "../../../../CS1C_BulkClub/members.db"
#elif __linux__
    #define MEMBERS_PATH "../CS1C_BulkClub/members.db"
#else
    #define MEMBERS_PATH "..\\CS1C_BulkClub\\members.db"
#endif

#if __APPLE__ && TARGET_OS_MAC
    #define INVENTORY_PATH "../../../../CS1C_BulkClub/inventory.db"
#elif __linux__
    #define INVENTORY_PATH "../CS1C_BulkClub/inventory.db"
#else
    #define INVENTORY_PATH "..\\CS1C_BulkClub\\inventory.db"
 #endif

#if __APPLE__ && TARGET_OS_MAC
    #define MEMBER_PATH "../../../../CS1C_BulkClub/warehouse_shoppers.txt"
#elif __linux__
    #define MEMBER_PATH "../CS1C_BulkClub/warehouse_shoppers.txt"
#else
    #define MEMBER_PATH "..\\CS1C_BulkClub\\warehouse_shoppers.txt"
#endif

#if __APPLE__ && TARGET_OS_MAC
    #define SALES_PATH "../../../../CS1C_BulkClub/sales.txt"
#elif __linux__
    #define SALES_PATH "../CS1C_BulkClub/sales.txt"
#else
    #define SALES_PATH "..\\CS1C_BulkClub\\sales.txt"
#endif

#endif

#define USE_DEBUG
// debug macro
#ifdef USE_DEBUG
#include <QDebug>

#define DEBUG qDebug().noquote().nospace()

#endif

#define USE_TAX
// tax macro
#ifdef USE_TAX
// sales tax
#define SALES_TAX 0.0075

#endif

#endif // DEFINES_H
