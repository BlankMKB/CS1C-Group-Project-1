#include "mainwindow.h"
#include <QApplication>
#include "dbmanager.h"
#include "inventorymanager.h"

/*************************************************************
 * Main Method
 *************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString memberPath, inventoryPath;

#if __APPLE__ && TARGET_OS_MAC
    memberPath = "../../../../CS1C_BulkClub/members.db";
#elif __linux__
    memberPath = "../CS1C_BulkClub/members.db";
#else
    memberPath = "..\\CS1C_BulkClub\\members.db";
#endif

#if __APPLE__ && TARGET_OS_MAC
    inventoryPath = "../../../../CS1C_BulkClub/inventory.db";
#elif __linux__
    inventoryPath = "../CS1C_BulkClub/inventory.db";
#else
    inventoryPath = "..\\CS1C_BulkClub\\inventory.db";
#endif

    DbManager* pDb = new DbManager(memberPath);
    pDb->ResetWithTextFile();

    InventoryManager* pIdb = new InventoryManager(inventoryPath);
    pIdb->ResetWithTextFile();
    return a.exec();
}
