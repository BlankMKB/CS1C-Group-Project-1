#include "mainwindow.h"
#include <QApplication>
#include "dbmanager.h"

/*************************************************************
 * Main Method
 *************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString path;

#if __APPLE__ && TARGET_OS_MAC
    path = "../../../../CS1C_BulkClub/members.db";
#elif __linux__
    path = "../CS1C_BulkClub/members.db";
#else
    path = "..\\CS1D_FastFood\\members.db";
#endif
    dbManager db(path);

    db.initialize();

    return a.exec();
}
