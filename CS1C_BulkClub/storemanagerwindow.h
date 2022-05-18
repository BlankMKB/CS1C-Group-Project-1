#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include "QtWidgets/qlabel.h"

#include "member.h"
#include "executivemember.h"

#include "dbmanager.h"
#include "membermanager.h"
#include "inventorymanager.h"

#define USE_PATHS
#include "defines.h"

namespace Ui {
class StoreManagerWindow;
}

class StoreManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoreManagerWindow(QWidget *parent = nullptr);
    ~StoreManagerWindow();

private slots:
    void on_logout_button_clicked();

    // sales report by date
    void on_dateByDayCB_currentIndexChanged(int index);
    void on_dateTypeByDayCB_currentIndexChanged(int index);

    // sales report by member type
    void on_typeByMemberCB_currentIndexChanged(int index);
    void on_dateByMemberCB_currentIndexChanged(int index);

    // member information
    void on_memberTypeCB_currentIndexChanged(int index);
    void on_memberInfoCB_currentIndexChanged(int index);
    void on_expirationMonthCB_currentIndexChanged(int index);
    void on_memberReceiptCB_currentIndexChanged(int index);

    // item search
    void on_itemSearchButton_clicked();
    void on_itemResetButton_clicked();

    // member search
    void on_memberSearchButton_clicked();
    void on_memberResetButton_clicked();

private:
    void SetTypesCB();
    void SetDateCB();
    void SetMemberCB();
    void SetExpirationMonthCB();
    void SetDropDownMenus();

private:
    void NoEdits(QTableWidget*);
    void ClearTable(QTableWidget*);

private:
    void SetMembersTW(QTableWidget*, const int&, const std::vector<Member>&);
    void SetMemberReceiptsTW(const Member& member);
    void SetMemberTotalsTW();

private:
    void SetItemsTW(QTableWidget*, const ItemList&, QLabel*);
    void SetItemTotalsTW();

private:
    std::vector<Member> MembersShoppedByDate(const Date&);
    std::vector<ItemList> SalesListByDate(const Date&);
    ItemList AllItemsByType(const int&, const Date&);


private:
    Ui::StoreManagerWindow *ui;  // Pointer to the instance of the StoreManagerWindow class object. (SELF)
    QWidget *parent;             // Pointer to the instance of parent window, MainWindow class object.

    DbManager* m_pDb;
    InventoryManager* m_pIdb;

    std::vector<std::pair<Member, Receipt>> m_Sales;
    std::vector<Member> m_MemberList;
    ItemList m_Inventory;
};

#endif // STOREMANAGERWINDOW_H
