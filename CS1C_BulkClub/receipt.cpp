#include "receipt.h"

Receipt::Receipt() {

}

Receipt::~Receipt() {

}

ItemList Receipt::receiptByDay(const Date& key) {
    return this->m_Receipt[key];
}

bool Receipt::add(const Date& day, Item& item, const int& quantity) {
    return this->m_Receipt[day].insert(&item, quantity);
}
