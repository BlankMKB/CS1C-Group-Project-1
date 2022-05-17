#ifndef MEMBERWINDOW_H
#define MEMBERWINDOW_H

#include <QDialog>
#include "QtWidgets/qtablewidget.h"
#include "dbmanager.h"
#include "inventorymanager.h"

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

private:
    void SetItemCB();
    void AddToTableWidget(const QString& itemName, const int& itemQuantity);
    void ClearTable(QTableWidget* tableWidget);
    void SetHeaderLabels();


private:
    Ui::MemberWindow *ui;
    QWidget* parent;

    Member m_CurrMember;
    ItemList m_Inventory;
    ItemList m_Cart;


    DbManager* m_pDb;
    InventoryManager* m_pIdb;
};

#endif // MEMBERWINDOW_H
