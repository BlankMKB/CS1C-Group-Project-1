#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QDialog>
#include "QtWidgets/qlabel.h"
#include "QtWidgets/qlistwidget.h"
#include "QtWidgets/qtablewidget.h"
#include "member.h"
#include "dbmanager.h"
#include "inventorymanager.h"
#include <queue>

//define member path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define MEMBERS_PATH "../../../../CS1C_BulkClub/members.db"
#elif __linux__
    #define MEMBERS_PATH "../CS1C_BulkClub/members.db"
#else
    #define MEMBERS_PATH "..\\CS1C_BulkClub\\members.db"
#endif

//define sales path for different OS
#if __APPLE__ && TARGET_OS_MAC
    #define INVENTORY_PATH "../../../../CS1C_BulkClub/inventory.db"
#elif __linux__
    #define INVENTORY_PATH "../CS1C_BulkClub/inventory.db"
#else
    #define INVENTORY_PATH "..\\CS1C_BulkClub\\inventory.db"
 #endif

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

    void on_deleteMemberButton_clicked();

    void on_editMembersTW_cellChanged(int row, int column);

    void on_updateMembersButton_clicked();

    void on_addItemButton_clicked();

    void on_deleteItemButton_clicked();

    void on_editItemsTW_cellChanged(int row, int column);

    void on_updateItemsButton_clicked();

private:
    void UpdateAll();

    void SetMembersCB();

    void SetMembersTW();

    void SetConversionLE();

    void SetConversionLE(QListWidget* listWidget, QLabel* label, const std::vector<Member>& conversions);



    void ClearTable(QTableWidget* tableWidget);

    void SetItemTotalsTW();

    void SetItemsCB();

private:
    Ui::AdministratorWindow *ui;  // Pointer to the instance of the AdministratorWindow class object. (SELF)
    QWidget *parent;              // Pointer to the instance of parent window, MainWindow class object.

    DbManager* m_pDb;
    InventoryManager* m_pIdb;

    std::vector<Member> m_MemberList;
    ItemList m_Inventory;
};

#endif // ADMINISTRATORWINDOW_H
