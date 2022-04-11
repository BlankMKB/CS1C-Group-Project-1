#include "mainwindow.h"
#include "ui_mainwindow.h"

/*************************************************************
 * Constructor for the MainWindow Class.
 *************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*************************************************************
 * Destructor for the MainWindow Class.
 *************************************************************/
MainWindow::~MainWindow()
{
    delete ui;

}

/*************************************************************
 * LOGIN BUTTON (On-Click Event) for the Main Window class.
 * This function will be called when the button has been
 * pressed and required information passes checks. This
 * function is of type void and does not return anything.
 *************************************************************/

void MainWindow::on_adminButton_clicked() {
    Admin* adminWindow = new Admin;
    adminWindow->setAttribute(Qt::WA_DeleteOnClose);
    adminWindow->setWindowTitle("admin login");
    adminWindow->show();
}

