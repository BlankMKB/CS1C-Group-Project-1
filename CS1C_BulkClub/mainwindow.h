#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administratorwindow.h"
#include "storemanagerwindow.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
};

QT_END_NAMESPACE

/*******************************************
 * MainWindow Class
 ******************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*******************************************
     * MainWindow Constructor
     ******************************************/
    MainWindow(QWidget *parent = nullptr);

    /*******************************************
     * MainWindow Destructor
     ******************************************/
    ~MainWindow();

private slots:
    /*******************************************
     * Login button prototype for when a user
     * click's the login button.
     ******************************************/
    void on_login_button_clicked();

private:
    Ui::MainWindow *ui;                // Pointer to the instance of the MainWindow class object.
    AdministratorWindow *adminWindow;  // Pointer to an instance of an AdmininstratorWindow class object.
    StoreManagerWindow *managerWindow; // Pointer to an instance of an StoreManagerWindow class object.
};
#endif // MAINWINDOW_H
