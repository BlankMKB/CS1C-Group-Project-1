#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QDialog>
#include <dbmanager.h>
#include <member.h>
#include <itemlist.h>

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

    void on_Add_Button_clicked();

    void on_Delete_Button_clicked();

    void on_Add_Item_Button_clicked();

    void on_Delete_Item_Button_clicked();

    void on_tabWidget_3_currentChanged(int index);

private:
    Ui::AdministratorWindow *ui;  // Pointer to the instance of the AdministratorWindow class object. (SELF)
    QWidget *parent;  // Pointer to the instance of parent window, MainWindow class object.
    dbManager *db;
    std::vector<Member*>CurrMember;
    ItemList CurrInventory;
};

#endif // ADMINISTRATORWINDOW_H
