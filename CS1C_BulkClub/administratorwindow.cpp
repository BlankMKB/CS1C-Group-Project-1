#include "administratorwindow.h"
#include "ui_administratorwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

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



void AdministratorWindow::on_Add_Button_clicked()
{
    QString name=ui->name_text->text();
    int id=ui->id_text->text().toInt();
    QString type=ui->type_cb->currentText();
    int day=ui->day_cb->currentText().toInt();
    int month=ui->month_cb->currentText().toInt();
    int year=ui->year_cb->currentText().toInt();
    bool type_flag;

    if(type=="Regular")
    {
        type_flag=false;
    }
    else
    {
        type_flag=true;
    }

    Date tempdate(day,month,year);
    Member tempmember(name,id,type_flag,tempdate);

    CurrMember.push_back(&tempmember);

    if(db->addMember(tempmember))
    {
        QMessageBox::information(this,"Added","Add Successful");
    }
    else
    {
        QMessageBox::warning(this,"Not Added","Add Not Successful");
    }
}


void AdministratorWindow::on_Delete_Button_clicked()
{
     int id=ui->delete_id_text->text().toInt();
     for(int i=0;i<CurrMember.size();i++)
     {
         if(id==CurrMember[i]->id())
         {
             Member*tempmem=CurrMember.at(i);
             delete tempmem;
         }
     }

     if(db->deleteMemberById(id))
     {
         QMessageBox::information(this,"Deleted","Delete Successful");
     }
     else
     {
         QMessageBox::warning(this,"Not Deleted","Delete Not Successful");
     }
}


void AdministratorWindow::on_Add_Item_Button_clicked()
{
    QString name=ui->itemname_text->text();
    int quantity=ui->itemquantity_text->text().toInt();
    float price=ui->itemprice_text->text().toFloat();

    Item*tempitem = new Item;
    tempitem->setName(name);
    tempitem->setQuantity(quantity);
    tempitem->setPrice(price);

    CurrInventory.insertInventory(tempitem);
    QMessageBox::information(this,"Added", "Add Successful");
    ui->itemname_text->clear();
    ui->itemquantity_text->clear();
    ui->itemprice_text->clear();
}


void AdministratorWindow::on_Delete_Item_Button_clicked()
{
    QString name=ui->delete_item_text->text();
    if(CurrInventory.removeItem(name))
    {
        QMessageBox::information(this,"Deleted","Delete Successful");

    }
    else
    {
        QMessageBox::information(this,"Not Deleted","Delete Not Successful");
    }
}

