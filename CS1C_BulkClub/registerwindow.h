#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QDialog>
#include <qmessagebox.h>

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

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
