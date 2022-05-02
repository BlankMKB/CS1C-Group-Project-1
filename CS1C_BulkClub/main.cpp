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

    QString path, Ipath;

#if __APPLE__ && TARGET_OS_MAC
    path = "../../../../CS1C_BulkClub/members.db";
#elif __linux__
    path = "../CS1C_BulkClub/members.db";
#else
    path = "..\\CS1D_FastFood\\members.db";
#endif

#if __APPLE__ && TARGET_OS_MAC
    Ipath = "../../../../CS1C_BulkClub/inventory.db";
#elif __linux__
    path = "../CS1C_BulkClub/members.db";
#else
    path = "..\\CS1D_FastFood\\members.db";
#endif

    std::vector<Member> members;
    Parser parser;

    parser.read(members);
    dbManager* db = new dbManager(path);


    db->initialize();
    db->print();

    InventoryManager* idb = new InventoryManager(Ipath);
    idb->initialize();


    return a.exec();
}
