#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

/**********************************************************
 * This is the default constructor for the StoreManager
 * Window Class. This function's purpose is to initialize
 * all the needed attributes/components apart of the
 * StoreManager Window Class.
 *********************************************************/
StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow)
{
    ui->setupUi(this);
    this->parent = this->parentWidget();
}

/**********************************************************
 * This is the destructor for the StoreManagerWindow Class.
 * This function will be called when the StoreManager
 * Class goes out of scope.
 *********************************************************/
StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}

/**********************************************************
 * LOGOUT BUTTON (On-Click Event) - This is the Store
 * Manager Class function for logging a manager out of their
 * session and returning them to the MainWindow.
 *********************************************************/
void StoreManagerWindow::on_logout_button_clicked()
{
    this->hide();
    //this->parent->show();
}

