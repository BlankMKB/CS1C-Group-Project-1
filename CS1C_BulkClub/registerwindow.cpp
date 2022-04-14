#include "registerwindow.h"
#include "ui_registerwindow.h"

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
