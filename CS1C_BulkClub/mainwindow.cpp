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
 * pressed.
 *************************************************************/
void MainWindow::on_loginButton_clicked() {
    LoginWindow* loginWindow = new LoginWindow;
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->setWindowTitle("Login");
    loginWindow->show();
}


/*************************************************************
 * REGISTER BUTTON (On-Click Event) for the Main Window class.
 * This function will be called when the button has been
 * pressed.
 *************************************************************/
void MainWindow::on_registerButton_clicked() {
    RegisterWindow* registerWindow = new RegisterWindow;
    registerWindow->setAttribute(Qt::WA_DeleteOnClose);
    registerWindow->setWindowTitle("Registration");
    registerWindow->show();
}

