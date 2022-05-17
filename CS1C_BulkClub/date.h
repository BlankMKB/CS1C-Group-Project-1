#ifndef DATE_H
#define DATE_H

#include <QDebug>

/*!
 * \class Date
 * \brief The Date Class
 * \details Stores the expiration dates of members in the format MM/DD/YYYY
 * \note This class has a defaulted constructor and destructor.
 */
class Date {
// constructors
public:
    /*!
     * \fn Date(const Date&)
     * \brief Copy constructor
     * \param otherDate: Date
     */
    Date(const Date& other);

    /*!
     * \fn Date(const int&, const int&, const int&)
     * \brief Date overloaded constructor
     * \param day: int
     * \param month: int
     * \param year: int
     */
    Date(const int& month, const int& day, const int& year);


// accessors
public:
    /*!
     * \fn Month()
     * \brief Returns the month
     * \return month: int
     */
    int Month() const;

    /*!
     * \fn Day()
     * \brief Returns the day
     * \return day: int
     */
    int Day() const;

    /*!
     * \fn Year()
     * \brief Returns the year
     * \return year: int
     */
    int Year() const;

    /*!
     * \fn PrintDate()
     * \brief For debug purposes
     * \details Prints date string
     */
    void PrintDate();

    /*!
     * \fn DateString()
     * \brief returns date string
     * \return dateString: QString
     */
    QString DateString() const;

// operators
public:
    /*!
     * \fn operator==(const Date&)
     * \brief overload equality operator
     * \return this dateString = other dateString
     */
    bool operator ==(const Date& other);

    /*!
     * \fn operator<(const Date&)
     * \brief overload < operator
     * \return this date < other date
     */
    bool operator<(const Date& other);

// static parse date
public:
    /*!
     * \fn ParseDate(const QString&)
     * \brief Parses date from QString line
     * \param line: QString
     * \return Date object
     */
    static Date ParseDate(const QString& line);

// defaulted constructor
public:
    /*!
     * \fn Date()
     * \brief Default constructor
     */
    Date() = default;

    /*!
     * \fn ~Date()
     * \brief Default destructor
     */
    ~Date() = default;

// variables
private:
    int     m_Month,        /*!< \var month: int */
            m_Day,          /*!< \var day: int */
            m_Year;         /*!< \var year: int */
    QString m_DateString;   /*!< \var date string: QString */

};
#endif // DATE_H
