#include "receipt.h"

Receipt::Receipt() {

}
/*
Receipt::Receipt(const Receipt& other) {
    for(size_t i = 0; i < other.size(); i++) {
        this->m_Receipt[i].first = other.receipt()[i].first;
        this->m_Receipt[i].second = other.receipt()[i].second;
    }
}*/

Receipt::~Receipt() {

}

ItemList Receipt::receiptByDay(const Date& key) {
    for(auto& x : this->m_Receipt) {
        if(x.first.dateString() == key.dateString()) {
            return x.second;
        }
    }
}

bool Receipt::add(const Date& day, Item* item, const int& quantity) {
    for(auto& x : this->m_Receipt) {
        if(x.first == day) {
            return x.second.insert(item, quantity);
        }
    }
    ItemList temp;
    temp.insert(item, quantity);
    this->m_Receipt.push_back(std::make_pair(day, temp));
    return false;
}

size_t Receipt::size() const {
    return this->m_Receipt.size();
}

std::vector<std::pair<Date, ItemList>> Receipt::receipt() const {
    return this->m_Receipt;
}

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
