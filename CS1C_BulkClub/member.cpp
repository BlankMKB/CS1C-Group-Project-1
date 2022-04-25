#include "member.h"

Member::Member(const QString& name, const int& id, const bool& type, const Date& date) : m_Name(name), m_Number(id), m_Type(type), m_ExpirationDate(date) {
    this->m_RunningTotal = 65;
}

QString Member::name() const {
    return this->m_Name;
}

int Member::id() const {
    return this->m_Number;
}

bool Member::type() const {
    return this->m_Type;
}

Date Member::expiration() const {
    return this->m_ExpirationDate;
}

float Member::runningTotal() const {
    return this->m_RunningTotal;
}

Receipt Member::receipt() const {
    return this->m_Receipt;
}

void Member::setName(const QString& name) {
    this->m_Name = name;
}

void Member::setID(const int& id) {
    this->m_Number = id;
}

void Member::setType(const bool& type) {
    this->m_Type = type;
}

void Member::setExpiration(const Date& date) {
    this->m_ExpirationDate = date;
}

void Member::setRunningTotal(const float& total) {
    this->m_RunningTotal = total;
}

void purchase(Item* item, const int& quantity, const Date& day) {

}
