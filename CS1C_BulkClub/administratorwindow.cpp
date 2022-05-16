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

    m_MemberList = m_pDb->AllMembers();

    SetMembersCB();
    SetMembersTW();
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
    m_MemberList.clear();
    m_MemberList = m_pDb->AllMembers();

    this->ui->memberNameLE->clear();
    this->ui->memberIDLE->clear();
    this->ui->memberTypeLE->clear();
    this->ui->memberExpirationLE->clear();

    SetMembersTW();
    SetMembersCB();
}

void AdministratorWindow::SetMembersCB() {
    this->ui->deleteMemberCB->clear();
    for(const auto& member : m_MemberList) {
        this->ui->deleteMemberCB->addItem(member.Name());
    }
}

void AdministratorWindow::SetMembersTW() {
    this->ui->editMembersTW->clear();
    while(this->ui->editMembersTW->rowCount() > 0) {
        this->ui->editMembersTW->removeRow(0);
    }
    QStringList headerLabels = { "Name", "ID", "Type", "Expiration", "Running Total" };
    this->ui->editMembersTW->setHorizontalHeaderLabels(headerLabels);

    for(size_t i = 0; i < m_pDb->MemberCount(); i++) {
        this->ui->editMembersTW->insertRow(i);

        QString type;
        for(size_t col = 0; col < 5; col++) {
            QTableWidgetItem* item = new QTableWidgetItem;

            /* switch case format:
             * 0: member name
             * 1: member id
             * 2: member type
             * 3: member expiration
             * 4: running total
             */
            switch(col) {
            // member name
            case 0:
                item->setText(m_MemberList[i].Name());
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

            // member id
            case 1:
                item->setText(QString::number(m_MemberList[i].Id()));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                break;

            // member type
            case 2:
                type = m_MemberList[i].Type() ? "Executive" : "Regular";
                item->setText(type);
                break;

            // member expiration
            case 3:
                item->setText(m_MemberList[i].Expiration().DateString());
                break;

            // running total
            case 4:
                item->setText("$" + QString::number(m_MemberList[i].RunningTotal(), 'f', 2));
                break;
            }

            // align text to center
            item->setTextAlignment(Qt::AlignCenter);

            // add item to table
            this->ui->editMembersTW->setItem(i, col, item);
        }
        //resize column width to widest column
        this->ui->editMembersTW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}

void AdministratorWindow::on_deleteMemberButton_clicked() {
    QString name = this->ui->deleteMemberCB->currentText();

    for(size_t i = 0; i < m_MemberList.size(); i++) {
        if(m_MemberList[i].Name() == name) {
            if(m_pDb->DeleteMemberById(m_MemberList[i].Id())) {
                qDebug().noquote().nospace() << "Member " << m_MemberList[i].Name() << " deleted successfully";
                m_MemberList.erase(m_MemberList.begin() + i);
            }
            SetMembersCB();
            SetMembersTW();
            break;
        }
    }
}


void AdministratorWindow::on_editMembersTW_cellChanged(int row, int column) {
    Member* p_EditedMember = nullptr;
    for(auto& member : m_MemberList) {
        if(member.Name() == this->ui->editMembersTW->item(row, 0)->text()) {
            p_EditedMember = &member;
            break;
        }
    }

    if(!p_EditedMember) {
        return;
    }

    bool wasRegular = p_EditedMember->Type();

    QString editedText = this->ui->editMembersTW->item(row, column)->text();

    switch(column) {
    case 0:
        p_EditedMember->SetName(editedText);
        break;
    case 1:
        p_EditedMember->SetID(editedText.toInt());
        break;
    case 2:
        p_EditedMember->SetType(editedText.toUpper() == "EXECUTIVE" ? true : false);
        if(!wasRegular && p_EditedMember->Type()) {
            p_EditedMember->SetRunningTotal(p_EditedMember->RunningTotal() + 55);
        }
        break;
    case 3:
        if(this->ui->editMembersTW->item(row, column)->text().count('/') != 2) {
            QMessageBox::critical(this, "Error", "Please input date in the format MM/DD/YYYY");
            break;
        }
            p_EditedMember->SetExpiration(Date::ParseDate(editedText));
        break;
    case 4:
        if(editedText.contains("$")) {
            break;
        }
        p_EditedMember->SetRunningTotal(editedText.toFloat());
        break;
    }
}


void AdministratorWindow::on_updateMembersButton_clicked() {
    for(const auto& member : m_MemberList) {
        m_pDb->UpdateMember(member);
    }

    m_MemberList = m_pDb->AllMembers();

    SetMembersCB();
    SetMembersTW();
}

