#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "administratorwindow.h"
#include "storemanagerwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    /*******************************************
     * Login button prototype for when a user
     * click's the login button.
     ******************************************/
    void on_login_button_clicked();

private:
    Ui::Login *ui;
    AdministratorWindow *adminWindow;  // Pointer to an instance of an LogininstratorWindow class object.
    StoreManagerWindow *managerWindow; // Pointer to an instance of an StoreManagerWindow class object.
};

#endif // LOGIN_H
