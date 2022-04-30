#include "member.h"

//default constructor
Member::Member() {

}

//overloaded constructor
Member::Member(const QString& name, const int& id, const bool& type, const Date& date) : m_Name(name), m_Number(id), m_Type(type), m_ExpirationDate(date), m_RunningTotal(65) {

}

//name
QString Member::name() const {
    return this->m_Name;
}

//id
int Member::id() const {
    return this->m_Number;
}

//member type
bool Member::type() const {
    return this->m_Type;
}

//expiration date
Date Member::expiration() const {
    return this->m_ExpirationDate;
}

//running total
float Member::runningTotal() const {
    return this->m_RunningTotal;
}

//receipt
Receipt Member::receipt() const {
    return this->m_Receipt;
}

//set name
void Member::setName(const QString& name) {
    this->m_Name = name;
}

//set id
void Member::setID(const int& id) {
    this->m_Number = id;
}

//set member type
void Member::setType(const bool& type) {
    this->m_Type = type;
}

//set expiration date
void Member::setExpiration(const Date& date) {
    this->m_ExpirationDate = date;
}

//set receipt
void Member::setReceipt(const Receipt& receipt) {
    this->m_Receipt = receipt;
}

//add to running total
void Member::addRunningTotal(const float& total) {
    this->m_RunningTotal += total;
}

//purchase an item
void Member::purchase(Item* item, const int& quantity, const Date& day) {
    float total = item->price() * quantity;
    this->m_RunningTotal += total;
    this->m_Receipt.add(day, item, quantity);
}
