#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include "QtWidgets/qlabel.h"
#include "member.h"
#include "executivemember.h"
#include "dbmanager.h"
#include "inventorymanager.h"

#define USE_PATHS
#include "paths.h"

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

    //sales report by date
    void on_dateByDayCB_currentIndexChanged(int index);

    void on_dateTypeByDayCB_currentIndexChanged(int index);

    //sales report by member type
    void on_typeByMemberCB_currentIndexChanged(int index);

    void on_dateByMemberCB_currentIndexChanged(int index);

    //member information
    void on_memberTypeCB_currentIndexChanged(int index);

    void on_memberInfoCB_currentIndexChanged(int index);

    void on_expirationMonthCB_currentIndexChanged(int index);

    void on_itemSearchButton_clicked();

    void on_itemResetButton_clicked();

    void on_memberSearchButton_clicked();

    void on_memberResetButton_clicked();

    void on_memberReceiptCB_currentIndexChanged(int index);

private:
   Date parseDate(const QString&);

private:
    void setTypesCB();
    void setDateCB();
    void setMemberCB();
    void setExpirationMonthCB();
    void setDropDownMenus();
    void setMemberReceiptsTW(const Member& member);

private:
    void noEdits(QTableWidget*);
    void clearTable(QTableWidget*);

private:
    void setMembersTW(QTableWidget*, const int&, const std::vector<Member>&);
    void setMemberTotalsTW();

private:
    void setItemsTW(QTableWidget*, const ItemList&, QLabel*);
    void setItemTotalsTW();

private:
    std::vector<Member> membersShoppedByDate(const Date&);
    std::vector<ItemList> salesListByDate(const Date&);
    ItemList allItemsByType(const int&, const Date&);


private:
    Ui::StoreManagerWindow *ui;  // Pointer to the instance of the StoreManagerWindow class object. (SELF)
    QWidget *parent;             // Pointer to the instance of parent window, MainWindow class object.
    DbManager* m_pDb;
    InventoryManager* m_pIdb;

    std::vector<Member> m_MemberList;
    std::vector<std::pair<Member, Receipt>> m_Sales;
    ItemList m_Inventory;




};

#endif // STOREMANAGERWINDOW_H
