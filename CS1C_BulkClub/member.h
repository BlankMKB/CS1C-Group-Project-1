#ifndef MEMBER_H
#define MEMBER_H

#define SALES_TAX 0.0775

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
    QString Name() const;

    /*!
     * \brief return member id
     * \return id: int
     */
    int Id() const;

    /*!
     * \brief return member type. regular: false, executive: true
     * \return type: bool
     */
    bool Type() const;

    /*!
     * \brief returns emmber expiration
     * \return expiration: Date
     */
    Date Expiration() const;

    /*!
     * \brief return member's running total
     * \return runningTotal: float
     */
    float RunningTotal() const;

    /*!
     * \brief returns member receipt
     * \return receipt: Receipt
     */
    Receipt receipt() const;

    /*!
     * \brief set member name
     * \param name: QString
     */
    void SetName(const QString&);

    /*!
     * \brief sets member id
     * \param id: int
     */
    void SetID(const int&);

    /*!
     * \brief sets member type
     * \param type: bool
     */
    void SetType(const bool&);

    /*!
     * \brief sets member expiration date
     * \param expiration: Date
     */
    void SetExpiration(const Date&);

     /*!
      * \brief set receipt
      * \param otherReceipt: Receipt
      */
     void SetReceipt(const Receipt&);

    /*!
     * \brief sets running total
     * \param total: float
     */
     void SetRunningTotal(const float&);

     /*!
      * \brief purchases item and adds it to member's receipt
      * \param item: Item*`
      * \param quantity: int
      * \param date: Date
      */
     void Purchase(Item*, const Date&);

     /*!
      * \brief virtual functionf for rebate amount
      * \return rebateAmount: float
      */
     virtual float RebateAmount() const;
};

namespace std {
template<>
struct less<Member> {
    bool operator()(const Member& one, const Member& two) const {
        return one.Id() < two.Id();
    }
};
}
#endif // MEMBER_H
