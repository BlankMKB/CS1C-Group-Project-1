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

    DbManager* p_Db = new DbManager(MEMBERS_PATH);
    //p_Db->ResetWithTextFile();
    p_Db->InitializeMemberDB();

    InventoryManager* p_Idb = new InventoryManager(INVENTORY_PATH);
    //p_Idb->ResetWithTextFile();
    p_Idb->InitializeInventoryDB();

    return a.exec();
}
