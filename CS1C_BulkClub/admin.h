#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "administratorwindow.h"
#include "storemanagerwindow.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    /*******************************************
     * Login button prototype for when a user
     * click's the login button.
     ******************************************/
    void on_login_button_clicked();

private:
    Ui::Admin *ui;
    AdministratorWindow *adminWindow;  // Pointer to an instance of an AdmininstratorWindow class object.
    StoreManagerWindow *managerWindow; // Pointer to an instance of an StoreManagerWindow class object.
};

#endif // ADMIN_H
