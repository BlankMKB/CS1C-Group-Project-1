#include "salesreport.h"

SalesReport::SalesReport() {

}

SalesReport::~SalesReport() {

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
