#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administratorwindow.h"
#include "storemanagerwindow.h"
#include "admin.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
};

QT_END_NAMESPACE

/*******************************************
 * MainWindow Class
 ******************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*******************************************
     * MainWindow Constructor
     ******************************************/
    MainWindow(QWidget *parent = nullptr);

    /*******************************************
     * MainWindow Destructor
     ******************************************/
    ~MainWindow();

private slots:


    void on_adminButton_clicked();

private:
    Ui::MainWindow *ui;                // Pointer to the instance of the MainWindow class object.
};
#endif // MAINWINDOW_H
