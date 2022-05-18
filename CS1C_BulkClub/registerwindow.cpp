#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "dbmanager.h"

/**********************************************************
 * This is the default constructor for the RegisterWindow
 * class.
 *********************************************************/
RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

/**********************************************************
 * This is the destructor for the RegisterWindow class.
 *********************************************************/
RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked() {

    if(!ValidInput()) { return; }

    QString name = this->ui->nameLE->text();
    int id = this->ui->idLE->text().toInt();
    bool type = this->ui->typeCB->currentText() == "Executive" ? true : false;
    Date expiration = Date::ParseDate(this->ui->dateLE->text());

    Member* p_Member;
    p_Member = type ? new ExecutiveMember(name, id, type, expiration) : new Member(name, id, type, expiration);
    DbManager* p_Db = new DbManager(MEMBERS_PATH);
    p_Db->AddMember(*p_Member);
    delete p_Db;
    delete p_Member;

    close();
    QMessageBox::information(this, "Info", "You may now log in using the login feature");
    return;
}


bool RegisterWindow::ValidInput() {
    if(this->ui->nameLE->text() == "" ||
       this->ui->idLE->text() == "" ||
       this->ui->dateLE->text() == "") {
        QMessageBox::critical(this, "Error", "One or more text fields are empty");
        return false;
    }

    if(this->ui->dateLE->text().count('/') != 2) {
        QMessageBox::critical(this, "Error", "Please input date in the format MM/DD/YYYY");
        return false;
    }

    DbManager* p_Db = new DbManager(MEMBERS_PATH);
    std::vector<Member> memberList = p_Db->AllMembers();

    for(const auto& member : memberList) {
        if(this->ui->idLE->text().toInt() == member.Id()) {
            QMessageBox::critical(this, "Error", "Member ID in use. Please enter a different ID");
            return false;
        }
    }

    return true;
}
