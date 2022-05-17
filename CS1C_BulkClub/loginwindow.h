#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include "administratorwindow.h"
#include "storemanagerwindow.h"
#include "memberwindow.h"

#define USE_PATHS
#include "defines.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_login_button_clicked();

private:
    void AdminLogin();
    void ManagerLogin();
    void MemberLogin();

private:
    Ui::LoginWindow *ui;

    AdministratorWindow *adminWindow;  // Pointer to an instance of an AdmininstratorWindow class object.

    StoreManagerWindow *managerWindow; // Pointer to an instance of an StoreManagerWindow class object.

    MemberWindow* m_MemberWindow; // Pointer to an instance of a MemberWindow
};

#endif // LOGINWINDOW_H
