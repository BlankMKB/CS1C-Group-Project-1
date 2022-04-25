#include "salesreport.h"

SalesReport::SalesReport() {

}

SalesReport::~SalesReport() {

}

std::vector<ItemList> SalesReport::salesListByDate(const Date& day) {
    std::vector<ItemList> salesReport;
    for(auto& x : this->m_Sales) {
        salesReport.push_back(x.second.receiptByDay(day));
    }

    return salesReport;
}

std::vector<Receipt> SalesReport::salesListByType(const bool& type) {
    std::vector<Receipt> salesReport;
    for(auto& x : this->m_Sales) {
        if(x.first.type() == type) {
            salesReport.push_back(x.second);
        }
    }

    return salesReport;
}
