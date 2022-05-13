#include "member.h"

//default constructor
Member::Member() {

}

//overloaded constructor
Member::Member(const QString& name, const int& id, const bool& type, const Date& date) : m_Name(name), m_Number(id), m_Type(type), m_ExpirationDate(date), m_RunningTotal(65) {

}

//name
QString Member::Name() const {
    return m_Name;
}

//id
int Member::Id() const {
    return m_Number;
}

//member type
bool Member::Type() const {
    return m_Type;
}

//expiration date
Date Member::Expiration() const {
    return m_ExpirationDate;
}

//running total
float Member::RunningTotal() const {
    return m_RunningTotal;
}

//receipt
Receipt Member::receipt() const {
    return m_Receipt;
}

//set name
void Member::SetName(const QString& name) {
    m_Name = name;
}

//set id
void Member::SetID(const int& id) {
    m_Number = id;
}

//set member type
void Member::SetType(const bool& type) {
    m_Type = type;
}

//set expiration date
void Member::SetExpiration(const Date& date) {
    m_ExpirationDate = date;
}

//set receipt
void Member::SetReceipt(const Receipt& receipt) {
    m_Receipt = receipt;
}

//add to running total
void Member::SetRunningTotal(const float& total) {
    m_RunningTotal = total;
}

//purchase an item
void Member::Purchase(Item* item, const Date& day) {
    float total = item->Price() * item->Quantity();
    m_RunningTotal += total;
    m_Receipt.Add(day, item);
}

//rebate amount
float Member::RebateAmount() const {
    return 0;
}
