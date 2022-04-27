#include "receipt.h"

Receipt::Receipt() {

}

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
        if(x.first.dateString() == day.dateString()) {
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
