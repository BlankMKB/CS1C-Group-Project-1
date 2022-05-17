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
    if(ui->user_type_combo->currentText() == "Administrator"){
        if(ui->username_textbox->text() == "admin" && ui->password_textbox->text() == "guest") {
            this->hide();                                        // Hide the main window.
            this->adminWindow = new AdministratorWindow(this);   // Create a new instance of the admin window.
            this->adminWindow->setModal(true);                   // Set the model to the admin window.
            this->adminWindow->show();                           // Show the admin window.
            ui->user_type_combo->setCurrentIndex(0);             // Reset the index of the 'user_type' ComboBox.
        }
        else {
            // Alerts if login failed
            QMessageBox::critical(this, "Login Failed", "Invalid username or password");
            return;
        }
    } else if(ui->user_type_combo->currentText() == "Store Manager") {
        if(ui->username_textbox->text() == "manager" && ui->password_textbox->text() == "guest") {
            this->hide();                                        // Hide the main window.
            this->managerWindow = new StoreManagerWindow(this);  // Create a new instance of the manager window.
            this->managerWindow->setModal(true);                 // Set the model to the manager window.
            this->managerWindow->show();                         // Show the manager window.
            ui->user_type_combo->setCurrentIndex(0);             // Reset the index of the 'user_type' ComboBox.
        }
        else {
            // Alerts if login failed
            QMessageBox::critical(this, "Login Failed", "Invalid username or password");
            return;
        }
    }
    else {
        if(ui->username_textbox->text() == "" || ui->password_textbox->text() == "") {
            QMessageBox::critical(this, "Login Failed", "One or more fields are empty");
            return;
        }
        DbManager* p_Db = new DbManager(MEMBERS_PATH);

        QString name = this->ui->username_textbox->text();
        QString id = this->ui->password_textbox->text();
        Member* p_Member = nullptr;

        auto memberList = p_Db->AllMembers();

        for(auto& member : memberList) {
            if(member.Name() == name && member.Id() == id.toInt()) {
                p_Member = &member;
            }
        }

        if(!p_Member) {
            // Alerts if login failed
            QMessageBox::critical(this, "Login Failed", "Invalid username or password");
            return;
        }
        delete p_Db;

        this->hide();
        m_MemberWindow = new MemberWindow(this, p_Member);
        m_MemberWindow->setModal(true);
        m_MemberWindow->show();
        m_MemberWindow->SetCurrMember(*p_Member);
    }



}

