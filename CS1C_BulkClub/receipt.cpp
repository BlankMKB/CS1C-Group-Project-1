#include "receipt.h"

//default constructor
Receipt::Receipt() {

}

//destructor
Receipt::~Receipt() {

}

//receipt
std::vector<std::pair<Date, ItemList>> Receipt::receipt() const {
    return this->m_Receipt;
}

//size
size_t Receipt::size() const {
    return this->m_Receipt.size();
}

//receipt by date
ItemList Receipt::receiptByDay(const Date& key) {
    for(auto& x : this->m_Receipt) {
        if(x.first.dateString() == key.dateString()) {
            return x.second;
        }
    }
}

//add item
bool Receipt::add(const Date& day, Item* item, const int& quantity) {
    //for each element in receip
    for(auto& x : this->m_Receipt) {
        //add to date
        if(x.first == day) {
            x.second.insert(item, quantity);
            //not a new day
            return false;
        }
    }
    //else make a new item list with a new date and push it back to receipt
    ItemList temp;
    temp.insert(item, quantity);
    this->m_Receipt.push_back(std::make_pair(day, temp));

    return true;
}

//receipt string
QString Receipt::receiptString() const {
    if(this->m_Receipt.empty()) {
        return "";
    }

    QString str = "";
    QString date, list;
    for(size_t i = 0; i < this->m_Receipt.size(); i ++) {
        date = "#" + this->m_Receipt[i].first.dateString();
        list = this->m_Receipt[i].second.itemListString();

        if(i + 1 == this->m_Receipt.size()) {
            str += date + ", " + list + " ";
            break;
        }
        str += date + ", " + list + ", ";

        date = "";
        list = "";
    }

    return str;
}
