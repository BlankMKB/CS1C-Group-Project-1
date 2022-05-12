#include "member.h"

//default constructor
Member::Member() {

}

//overloaded constructor
Member::Member(const QString& name, const int& id, const bool& type, const Date& date) : m_Name(name), m_Number(id), m_Type(type), m_ExpirationDate(date), m_RunningTotal(65) {

}

//name
QString Member::name() const {
    return m_Name;
}

//id
int Member::id() const {
    return m_Number;
}

//member type
bool Member::type() const {
    return m_Type;
}

//expiration date
Date Member::expiration() const {
    return m_ExpirationDate;
}

//running total
float Member::runningTotal() const {
    return m_RunningTotal;
}

//receipt
Receipt Member::receipt() const {
    return m_Receipt;
}

//set name
void Member::setName(const QString& name) {
    m_Name = name;
}

//set id
void Member::setID(const int& id) {
    m_Number = id;
}

//set member type
void Member::setType(const bool& type) {
    m_Type = type;
}

//set expiration date
void Member::setExpiration(const Date& date) {
    m_ExpirationDate = date;
}

//set receipt
void Member::setReceipt(const Receipt& receipt) {
    m_Receipt = receipt;
}

//add to running total
void Member::setRunningTotal(const float& total) {
    m_RunningTotal = total;
}

//purchase an item
void Member::purchase(Item* item, const Date& day) {
    float total = item->price() * item->quantity();
    m_RunningTotal += total;
    m_Receipt.add(day, item);
}

//rebate amount
float Member::rebateAmount() const {
    return 0;
}
