#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "administratorwindow.h"
#include "storemanagerwindow.h"
#include "registerwindow.h"
#include "loginwindow.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
};

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;                // Pointer to the instance of the MainWindow class object.
};
#endif // MAINWINDOW_H
