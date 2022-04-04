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
   this->parent->show();
}

