#ifndef MEMBERWINDOW_H
#define MEMBERWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "QtWidgets/qtablewidget.h"


#include "dbmanager.h"
#include "membermanager.h"
#include "inventorymanager.h"

#define USE_PATHS
#define USE_DEBUG
#include "defines.h"

namespace Ui {
class MemberWindow;
}

class MemberWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MemberWindow(QWidget *parent = nullptr, Member* member = nullptr);
    ~MemberWindow();

public:
    inline void SetCurrMember(Member member) { m_CurrMember = member; }

private slots:
    void on_addToCartButton_clicked();

    void on_purchaseButton_clicked();

    void on_logout_button_clicked();

private:
    void SetHeaderLabels();
    void SetItemCB();
    void ClearTable(QTableWidget* tableWidget);
    void AddToCart(const QString& itemName, const int& itemQuantity);


private:
    Ui::MemberWindow *ui;
    QWidget* parent;

    Member m_CurrMember;
    ItemList m_Inventory;
    ItemList m_Cart;


    DbManager* m_pDb;
    MemberManager* m_pMdb;
    InventoryManager* m_pIdb;
};

#endif // MEMBERWINDOW_H
