#include "date.h"

//default constructor
Date::Date() : m_Month(0), m_Day(0), m_Year(0) {

}

//copy constructor
Date::Date(const Date& other) {
    this->m_Month = other.m_Month;
    this->m_Day = other.m_Day;
    this->m_Year = other.m_Year;
    this->m_DateString = other.m_DateString;
}

//overloaded constructor
Date::Date(const int& month, const int& day, const int& year) : m_Month(month), m_Day(day), m_Year(year) {
    this->m_DateString = QString::number(this->m_Month) + "/" + QString::number(this->m_Day) + "/" + QString::number(this->m_Year);
}

//day
int Date::day() const {
    return this->m_Day;
}

//month
int Date::month() const {
    return this->m_Month;
}

//year
int Date::year() const {
    return this->m_Year;
}

//print
void Date::print() {
    qDebug() << this->m_DateString;
}

//date string
QString Date::dateString() const {
    return this->m_DateString;
}

//operator==
bool Date::operator==(const Date& other) {
    return (this->m_DateString == other.m_DateString);
}

//operator<
bool Date::operator<(const Date& other) {
    return this->m_Day < other.m_Day;
}
