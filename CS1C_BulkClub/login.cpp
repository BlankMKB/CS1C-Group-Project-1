#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Admin::on_login_button_clicked()
{

    // Check for a username & password match in the database.


    // Log the date/time of when the Bulk Club services is being accessed.


    // Display the proper window with data needed for the user with certain access rights.


    // Depending on ComboBox option selected continue... (Temporary Solution)
    if(ui->user_type_combo->currentText() == "Administrator"){
        this->hide();                                        // Hide the main window.
        this->adminWindow = new AdministratorWindow(this);   // Create a new instance of the admin window.
        this->adminWindow->setModal(true);                   // Set the model to the admin window.
        this->adminWindow->show();                           // Show the admin window.
        ui->user_type_combo->setCurrentIndex(0);             // Reset the index of the 'user_type' ComboBox.
    } else if(ui->user_type_combo->currentText() == "Store Manager"){
        this->hide();                                        // Hide the main window.
        this->managerWindow = new StoreManagerWindow(this);  // Create a new instance of the manager window.
        this->managerWindow->setModal(true);                 // Set the model to the manager window.
        this->managerWindow->show();                         // Show the manager window.
        ui->user_type_combo->setCurrentIndex(0);             // Reset the index of the 'user_type' ComboBox.
    }
}
