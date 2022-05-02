#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_login_button_clicked()
{
    // Check for a username & password match in the database
    if(ui->username_textbox->text() == "" && ui->password_textbox->text() == "")
    {
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
    else
    {
        // Alerts if login failed
        QMessageBox::critical(this, "Login Failed", "Invalid username or password");
    }

    // Log the date/time of when the Bulk Club services is being accessed.


    // Display the proper window with data needed for the user with certain access rights.



}

