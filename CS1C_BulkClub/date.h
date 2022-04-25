#ifndef DATE_H
#define DATE_H

class Date {
public:
    int m_Day; /*!< \var day */
    int m_Month; /*!< \var month*/
    int m_Year; /*!< \var year*/

public:
    /*!
     * \brief Date default constructor
     */
    Date() : m_Day(0), m_Month(0), m_Year(0) {

    }

    /*!
     * \brief Date overloaded constructor
     * \param day
     * \param month
     * \param year
     */
    Date(const int& day, const int& month, const int& year) : m_Day(day), m_Month(month), m_Year(year) {

    }

    /*!
     * \brief returns the day
     * \return day
     */
    int day() const {
        return this->m_Day;
    }

    /*!
     * \brief returns the month
     * \return month
     */
    int month() const {
        return this->m_Month;
    }

    /*!
     * \brief returns the year
     * \return year
     */
    int year() const {
        return this->m_Year;
    }
};

#endif // DATE_H
