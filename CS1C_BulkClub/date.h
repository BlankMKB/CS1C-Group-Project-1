#ifndef DATE_H
#define DATE_H

#include <QDebug>

class Date {
private:
    int m_Day; /*!< \var day */
    int m_Month; /*!< \var month*/
    int m_Year; /*!< \var year*/
    QString m_DateString;

public:
    /*!
     * \brief Date default constructor
     */
    Date();

    Date(const Date&);

    /*!
     * \brief Date overloaded constructor
     * \param day
     * \param month
     * \param year
     */
    Date(const int&, const int&, const int&);

    /*!
     * \brief returns the day
     * \return day: int
     */
    int day() const;

    /*!
     * \brief returns the month
     * \return month: int
     */
    int month() const;

    /*!
     * \brief returns the year
     * \return year: int
     */
    int year() const;

    /*!
     * \brief returns date string
     * \return dateString: std::string
     */
    QString dateString() const;

    /*!
     * \brief debugs date
     */
    void print();

    /*!
     * \brief overload equality operator
     * \return this dateString = other dateString
     */
    bool operator ==(const Date&);
};

namespace std {
    template<>
    struct hash<Date> {
        size_t operator()(const Date& key) {
            return hash<QString>()(key.dateString());
        }
    };
}
#endif // DATE_H
