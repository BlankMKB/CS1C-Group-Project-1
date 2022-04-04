#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QDialog>

namespace Ui {
    class AdministratorWindow;
};

/*******************************************
 * AdministratorWindow Class
 ******************************************/
class AdministratorWindow : public QDialog
{
    Q_OBJECT

public:
    /*******************************************
     * AdministratorWindow Constructor
     ******************************************/
    explicit AdministratorWindow(QWidget *parent = nullptr);

    /*******************************************
     * AdministratorWindow Destructor
     ******************************************/
    ~AdministratorWindow();

private slots:
    /*******************************************
     * Logout button prototype for when a user
     * click's the logout button in the
     * AdministratorWindow Class.
     ******************************************/
    void on_logout_button_clicked();

private:
    Ui::AdministratorWindow *ui;  // Pointer to the instance of the AdministratorWindow class object. (SELF)
    QWidget *parent;              // Pointer to the instance of parent window, MainWindow class object.
};

#endif // ADMINISTRATORWINDOW_H
