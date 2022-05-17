#include "date.h"

//copy constructor
Date::Date(const Date& other) : m_Month(other.Month()),
                                m_Day(other.Day()),
                                m_Year(other.Year()),
                                m_DateString(other.DateString()) {

}

//overloaded constructor
Date::Date(const int& month, const int& day, const int& year) : m_Month(month),
                                                                m_Day(day),
                                                                m_Year(year),
                                                                m_DateString(QString::number(m_Month) + "/" +
                                                                             QString::number(m_Day) + "/" +
                                                                             QString::number(m_Year)) { }





//day
int Date::Day() const { return m_Day; }

//month
int Date::Month() const { return m_Month; }

//year
int Date::Year() const { return m_Year; }

//print
void Date::PrintDate() { qDebug() << m_DateString; }

//date string
QString Date::DateString() const { return m_DateString; }





//operator==
bool Date::operator==(const Date& other) { return (m_DateString == other.m_DateString); }

//operator<
bool Date::operator<(const Date& other) { return m_Day < other.m_Day; }





// ParseDate()
Date Date::ParseDate(const QString& line) {
    QStringList temp;
    int day, month, year;

    for(size_t i = 0; i < 3; i++) {

        /* switch case format
         * 0: month
         * 1: day
         * 2: year
         */
        switch (i) {
        // day
        case 0:
            temp = line.split("/");
            month = (temp[0]).toInt();
            break;
        // month
        case 1:
            temp = line.split("/");
            day = (temp[1]).toInt();
            break;
        // year
        case 2:
            temp = line.split("/");
            year = (temp[2]).toInt();
            break;
        default:
            break;
        }
    }

    Date date(month, day, year);

    return date;
}
