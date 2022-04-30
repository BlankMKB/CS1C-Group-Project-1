#ifndef SALESREPORT_H
#define SALESREPORT_H

#include "itemlist.h"
#include "receipt.h"
#include "member.h"

class SalesReport {
private:
     std::vector<std::pair<Member, Receipt>> m_Sales;

public:
    SalesReport();
    ~SalesReport();
    std::vector<ItemList> salesListByDate(const Date&);
    std::vector<Receipt> salesListByType(const bool&);
};

#endif // SALESREPORT_H
