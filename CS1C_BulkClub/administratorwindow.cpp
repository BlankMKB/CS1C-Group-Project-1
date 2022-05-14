#include "administratorwindow.h"
#include "ui_administratorwindow.h"
#include "mainwindow.h"

/**********************************************************
 * This is the default constructor for the Administrator
 * Window Class. This function will initialize all needed
 * components/attributes within the Administrator Window
 * Class.
 *********************************************************/
AdministratorWindow::AdministratorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministratorWindow)
{
    ui->setupUi(this);
    this->parent = this->parentWidget();

    this->ui->memberIDLE->setValidator( new QIntValidator(0, 10000000, this) );




    QString memberPath, inventoryPath;
#if __APPLE__ && TARGET_OS_MAC
    memberPath = "../../../../CS1C_BulkClub/members.db";
#elif __linux__
    memberPath = "../CS1C_BulkClub/members.db";
#else
    memberPath = "..\\CS1C_BulkClub\\members.db";
#endif

#if __APPLE__ && TARGET_OS_MAC
    inventoryPath = "../../../../CS1C_BulkClub/inventory.db";
#elif __linux__
    inventoryPath = "../CS1C_BulkClub/inventory.db";
#else
    inventoryPath = "..\\CS1C_BulkClub\\inventory.db";
#endif


    m_pDb = new DbManager(memberPath);
}

/**********************************************************
 * This is the destructor for AdministratorWindow Class.
 * This function will be called when the Administrator
 * Window Class goes out of scope.
 *********************************************************/
AdministratorWindow::~AdministratorWindow()
{
    delete ui;
}

/**********************************************************
 * LOGOUT BUTTON (On-Click Event) - This clas function is
 * for logging an administrator our of the session and
 * returning them to the MainWindow.
 *********************************************************/
void AdministratorWindow::on_logout_button_clicked()
{
   this->hide();
   //this->parent->show();
}

// add member
void AdministratorWindow::on_addMemberButton_clicked() {
    if(this->ui->memberNameLE->text() == ""
            || this->ui->memberIDLE->text() == ""
            || this->ui->memberTypeLE->text() == ""
            || this->ui->memberExpirationLE->text() == "") {
        QMessageBox::critical(this, "Error", "One or more text fields are empty");
        return;
    }

    if(this->ui->memberExpirationLE->text().count('/') != 2) {
        QMessageBox::critical(this, "Error", "Please input date in the format MM/DD/YYYY");
        return;
    }

    if(this->ui->memberTypeLE->text().toUpper() != "EXECUTIVE" && this->ui->memberTypeLE->text().toUpper() != "REGULAR") {
        QMessageBox::critical(this, "Error", "Invalid member type (Executive or Regular)");
        return;
    }


    QString name = this->ui->memberNameLE->text();
    int id = this->ui->memberIDLE->text().toInt();
    bool type = this->ui->memberTypeLE->text().toUpper() == "EXECUTIVE" ? true : false;
    Date date = Date::ParseDate(this->ui->memberExpirationLE->text());

    Member* pNewMember;
    if(type) {
        ExecutiveMember newMember(name, id, type, date);
        pNewMember = &newMember;
    }
    else {
        Member newMember(name, id, type, date);
        pNewMember = &newMember;
    }

    m_pDb->AddMember(*pNewMember);

    this->ui->memberNameLE->clear();
    this->ui->memberIDLE->clear();
    this->ui->memberTypeLE->clear();
    this->ui->memberExpirationLE->clear();

}
