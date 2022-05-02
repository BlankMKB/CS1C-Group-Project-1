#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include "member.h"
#include "executivemember.h"
#include "dbmanager.h"
#include "inventorymanager.h"

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

    void on_memberCB_currentIndexChanged(int index);

    void on_expirationMonthCB_currentIndexChanged(int index);

    void on_dateCB_currentIndexChanged(int index);

    void on_typeCB_currentIndexChanged(int index);

    void on_memberSearchButton_clicked();

    void on_itemSearchButton_clicked();

private:
    void setDropDownMenus();
    void setTypeCB();
    void setDateCB();
    void setMemberCB();
    void setExpirationMonthCB();
    void clearTable(QTableWidget*);
    std::vector<ItemList> salesListByDate(const Date&);

    Ui::StoreManagerWindow *ui;  // Pointer to the instance of the StoreManagerWindow class object. (SELF)
    QWidget *parent;             // Pointer to the instance of parent window, MainWindow class object.
    dbManager* m_pDb;
    InventoryManager* m_pIdb;

    std::vector<Member> m_MemberList;
    std::vector<std::pair<Member, Receipt>> m_Sales;
    ItemList m_Inventory;

};

#endif // STOREMANAGERWINDOW_H
