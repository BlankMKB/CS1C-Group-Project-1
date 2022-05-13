#include "date.h"

//default constructor
Date::Date() : m_Month(0), m_Day(0), m_Year(0) {

}

//copy constructor
Date::Date(const Date& other) {
    m_Month = other.m_Month;
    m_Day = other.m_Day;
    m_Year = other.m_Year;
    m_DateString = other.m_DateString;
}

//overloaded constructor
Date::Date(const int& month, const int& day, const int& year) : m_Month(month), m_Day(day), m_Year(year) {
    m_DateString = QString::number(m_Month) + "/" + QString::number(m_Day) + "/" + QString::number(m_Year);
}

//day
int Date::Day() const {
    return m_Day;
}

//month
int Date::Month() const {
    return m_Month;
}

//year
int Date::Year() const {
    return m_Year;
}

//print
void Date::PrintDate() {
    qDebug() << m_DateString;
}

//date string
QString Date::DateString() const {
    return m_DateString;
}

//operator==
bool Date::operator==(const Date& other) {
    return (m_DateString == other.m_DateString);
}

//operator<
bool Date::operator<(const Date& other) {
    return m_Day < other.m_Day;
}
