#ifndef DATE_H
#define DATE_H

class Date {
public:
    int _day; /*!< \var day */
    int _month; /*!< \var month*/
    int _year; /*!< \var year*/

public:
    /*!
     * \brief Date default constructor
     */
    Date() : _day(0), _month(0), _year(0) {

    }

    /*!
     * \brief Date overloaded constructor
     * \param day
     * \param month
     * \param year
     */
    Date(const int& day, const int& month, const int& year) : _day(day), _month(month), _year(year) {

    }

    /*!
     * \brief returns the day
     * \return day
     */
    int day() const {
        return this->_day;
    }

    /*!
     * \brief returns the month
     * \return month
     */
    int month() const {
        return this->_month;
    }

    /*!
     * \brief returns the year
     * \return year
     */
    int year() const {
        return this->_year;
    }
};

#endif // DATE_H
