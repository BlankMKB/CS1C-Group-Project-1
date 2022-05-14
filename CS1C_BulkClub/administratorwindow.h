#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QDialog>
#include "member.h"
#include "dbmanager.h"

namespace Ui {
    class AdministratorWindow;
};

class AdministratorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdministratorWindow(QWidget *parent = nullptr);
    ~AdministratorWindow();

private slots:
    void on_logout_button_clicked();

    void on_addMemberButton_clicked();

private:
    Ui::AdministratorWindow *ui;  // Pointer to the instance of the AdministratorWindow class object. (SELF)
    QWidget *parent;              // Pointer to the instance of parent window, MainWindow class object.

    DbManager* m_pDb;
};

#endif // ADMINISTRATORWINDOW_H
