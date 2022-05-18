#include "mainwindow.h"
#include <QApplication>

#include "dbmanager.h"
#include "membermanager.h"
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
    delete p_Db;

    MemberManager* p_Mdb = new MemberManager(ALL_MEMBERS_PATH);
    //p_Mdb->ResetWithTextFile();
    p_Mdb->InitializeMemberDB();
    delete p_Mdb;

    InventoryManager* p_Idb = new InventoryManager(INVENTORY_PATH);
    //p_Idb->ResetWithTextFile();
    p_Idb->InitializeInventoryDB();
    delete p_Idb;

    return a.exec();
}
