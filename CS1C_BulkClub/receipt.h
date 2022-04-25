#ifndef RECEIPT_H
#define RECEIPT_H

#include "itemlist.h"
#include "date.h"
#include <unordered_map>

class Receipt {
private:
    std::unordered_map<Date, ItemList> m_Receipt;

public:
    Receipt();

    ~Receipt();

    ItemList receiptByDay(const Date&);

    bool add(const Date&, Item&, const int&);
};

#endif // RECEIPT_H
