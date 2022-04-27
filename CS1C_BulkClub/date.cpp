#include "date.h"
Date::Date() : m_Day(0), m_Month(0), m_Year(0) {

}

Date::Date(const Date& other) {
    this->m_Day = other.m_Day;
    this->m_Month = other.m_Month;
    this->m_Year = other.m_Year;
    this->m_DateString = other.m_DateString;
}

Date::Date(const int& day, const int& month, const int& year) : m_Day(day), m_Month(month), m_Year(year) {
    this->m_DateString = QString::number(this->m_Day) + "/" + QString::number(this->m_Month) + "/" + QString::number(this->m_Year);
}

int Date::day() const {
    return this->m_Day;
}

int Date::month() const {
    return this->m_Month;
}

int Date::year() const {
    return this->m_Year;
}

QString Date::dateString() const {
    return this->m_DateString;
}

void Date::print() {
    qDebug() << this->m_DateString;
}

bool Date::operator==(const Date& other) {
    return (this->m_DateString == other.m_DateString);
}
