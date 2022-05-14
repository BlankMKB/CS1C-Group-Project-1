#ifndef DATE_H
#define DATE_H

#include <QDebug>

class Date {
private:
    int m_Month; /*!< \var month*/
    int m_Day; /*!< \var day */
    int m_Year; /*!< \var year*/
    QString m_DateString;

public:
    /*!
     * \brief default constructor
     */
    Date();

    /*!
     * \brief copy constructor
     * \param otherDate: Date
     */
    Date(const Date&);

    /*!
     * \brief Date overloaded constructor
     * \param day: int
     * \param month: int
     * \param year: int
     */
    Date(const int&, const int&, const int&);

    /*!
     * \brief returns the month
     * \return month: int
     */
    int Month() const;

    /*!
     * \brief returns the day
     * \return day: int
     */
    int Day() const;

    /*!
     * \brief returns the year
     * \return year: int
     */
    int Year() const;

    /*!
     * \brief for debug purposes: prints date string
     */
    void PrintDate();

    /*!
     * \brief returns date string
     * \return dateString: QString
     */
    QString DateString() const;

    /*!
     * \brief overload equality operator
     * \return this dateString = other dateString
     */
    bool operator ==(const Date&);

    /*!
     * \brief overload < operator
     * \return this date < other date
     */
    bool operator<(const Date&);


public:
    static Date ParseDate(const QString& line);

};
#endif // DATE_H
