#ifndef MEMBER_H
#define MEMBER_H

#include <QString>
#include <QDebug>
#include "date.h"
#include "item.h"
#include "receipt.h"

class Member {
protected:
    QString m_Name; /*!< \var member name */
    int m_Number; /*!< \var member id */
    bool m_Type; /*!< \var member type: regular: false, executive: true */
    Date m_ExpirationDate; /*!< \var expiration date */
    float m_RunningTotal; /*!< \var running total of all member fees */
    Receipt m_Receipt; /*!< \var receipt of member purchases */

public:
    /*!
     * \brief default constructor
     */
    Member();

    /*!
     * \brief overloaded constructor
     * \param name
     * \param id
     * \param type
     * \param expiration
     */
    Member(const QString&, const int&, const bool&, const Date&);

    /*!
     * \brief return member name
     * \return name: QString
     */
    QString name() const;

    /*!
     * \brief return member id
     * \return id: int
     */
    int id() const;

    /*!
     * \brief return member type. regular: false, executive: true
     * \return type: bool
     */
    bool type() const;

    /*!
     * \brief returns emmber expiration
     * \return expiration: Date
     */
    Date expiration() const;

    /*!
     * \brief return member's running total
     * \return runningTotal: float
     */
    float runningTotal() const;

    /*!
     * \brief returns member receipt
     * \return receipt: Receipt
     */
    Receipt receipt() const;

    /*!
     * \brief set member name
     * \param name: QString
     */
    void setName(const QString&);

    /*!
     * \brief sets member id
     * \param id: int
     */
    void setID(const int&);

    /*!
     * \brief sets member type
     * \param type: bool
     */
    void setType(const bool&);

    /*!
     * \brief sets member expiration date
     * \param expiration: Date
     */
    void setExpiration(const Date&);

     /*!
      * \brief set receipt
      * \param otherReceipt: Receipt
      */
     void setReceipt(const Receipt&);

    /*!
     * \brief sets running total
     * \param total: float
     */
     void addRunningTotal(const float&);

     /*!
      * \brief purchases item and adds it to member's receipt
      * \param item: Item*`
      * \param quantity: int
      * \param date: Date
      */
     void purchase(Item*, const Date&);
};

#endif // MEMBER_H
