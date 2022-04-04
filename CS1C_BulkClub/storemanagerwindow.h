#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>

namespace Ui {
class StoreManagerWindow;
}

/*******************************************
 * StoreManagerWindow Class
 ******************************************/
class StoreManagerWindow : public QDialog
{
    Q_OBJECT

public:
    /*******************************************
     * StoreManagerWindow Constructor
     ******************************************/
    explicit StoreManagerWindow(QWidget *parent = nullptr);

    /*******************************************
     * StoreManagerWindow Destructor
     ******************************************/
    ~StoreManagerWindow();

private slots:
    /*******************************************
     * Logout button prototype for when a user
     * click's the logout button in the
     * StoreManagerWindow Class.
     ******************************************/
    void on_logout_button_clicked();

private:
    Ui::StoreManagerWindow *ui;  // Pointer to the instance of the StoreManagerWindow class object. (SELF)
    QWidget *parent;             // Pointer to the instance of parent window, MainWindow class object.
};

#endif // STOREMANAGERWINDOW_H
