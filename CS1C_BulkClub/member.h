#ifndef MEMBER_H
#define MEMBER_H
#include <QString>
#include <QDebug>
#include "date.h"

class Member {
private:
    QString name; /*!< \var member name */
    int id; /*!< \var member id */
    Date expiration; /*!< \var expiration date */
    float receipt; /*!< \var running total of all member fees that are due */

public:
    /*!
     * \brief Member default constructor
    */
    Member() : name(""), id(0), expiration(Date()), receipt(0) {

    }

    /*!
     * \brief Member overloaded constructor
     * \param name
     * \param id
     * \param expiration
     * \param receipt
     */
    Member(const QString& name, const int& id, const Date& expiration, const float& receipt) : name(name), id(id), expiration(expiration), receipt(receipt) {

    }
};

#endif // MEMBER_H
