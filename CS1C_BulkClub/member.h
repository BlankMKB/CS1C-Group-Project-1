#ifndef MEMBER_H
#define MEMBER_H

#include <QString>
#include <QDebug>
#include "date.h"
#include "item.h"
#include "receipt.h"

#define USE_TAX
#include "defines.h"

/*!
 * \class Member
 * \brief The Member Class
 * \details This class stores member information.
 * \paragraph This class is the parent class of ExecutiveMember.
 * This class has a defaulted default and copy
 * constructor, and a defaulted operator=() function,
 * and a defaulted destructor.
 * \note virtual float RebateAmount() is meant to be overridden in ExecutiveMember.
 *           The default value of RebateAmount() returns 0.0f.
 */
class Member {
// constructors
public:
    /*!
     * \fn Member(const QString&, const int&, const bool& const Date&)
     * \brief Overloaded constructor
     * \param name
     * \param id
     * \param type
     * \param expiration
     */
    Member(const QString& name, const int& id, const bool& type, const Date& expiration);

// accessors
public:
    /*!
     * \fn Name()
     * \brief return member name
     * \return name: QString
     */
    QString Name() const;

    /*!
     * \fn Id()
     * \brief return member id
     * \return id: int
     */
    int Id() const;

    /*!
     * \fn Type()
     * \brief return member type. regular: false, executive: true
     * \return type: bool
     */
    bool Type() const;

    /*!
     * \fn Expiration()
     * \brief returns emmber expiration
     * \return expiration: Date
     */
    Date Expiration() const;

    /*!
     * \fn RunningTotal()
     * \brief return member's running total
     * \return runningTotal: float
     */
    float RunningTotal() const;

    /*!
     * \fn receipt()
     * \brief returns member receipt
     * \return receipt: Receipt
     */
    Receipt receipt() const;

     /*!
      * \fn RebateAmount()
      * \brief virtual functionf for rebate amount
      * \return rebateAmount: float
      */
     virtual float RebateAmount() const;

// mutators
public:
    /*!
     * \fn SetName(const QString&)
     * \brief set member name
     * \param name: QString
     */
    void SetName(const QString& name);

    /*!
     * \fn SetID(const int&)
     * \brief sets member id
     * \param id: int
     */
    void SetID(const int& id);

    /*!
     * \fn SetType(const bool&)
     * \brief sets member type
     * \param type: bool
     */
    void SetType(const bool& type);

    /*!
     * \fn SetExpiration(const Date&)
     * \brief sets member expiration date
     * \param expiration: Date
     */
    void SetExpiration(const Date& expiration);

     /*!
      * \fn SetReceipt(const Receipt&)
      * \brief set receipt
      * \param otherReceipt: Receipt
      */
     void SetReceipt(const Receipt& receipt);

    /*!
     * \fn SetRunningTotal(const float&)
     * \brief sets running total
     * \param total: float
     */
     void SetRunningTotal(const float&);

     /*!
      * \fn Purchase(item*, const Date&)
      * \brief purchases item and adds it to member's receipt
      * \param item: Item*`
      * \param quantity: int
      * \param date: Date
      */
     void Purchase(Item* item, const Date& date);

// defaulted constructors
public:
    /*!
     * \fn Member()
     * \brief Default constructor
     */
    Member() = default;

    /*!
     * \fn Member(const Member&)
     * \brief Default copy constructor
     * \param other: Member
     */
    Member(const Member& other) = default;

    /*!
     * \fn operator=(const Member&)
     * \brief default operator=()
     * \param other: Member
     */
    Member& operator=(const Member& other) = default;

    /*!
     * \fn ~Member()
     * \brief Default destructor
     */
    ~Member() = default;

// variables
protected:
    QString m_Name;             /*!< \var member name */
    int     m_Number;           /*!< \var member id */
    bool    m_Type;             /*!< \var member type: regular: false, executive: true */
    Date    m_ExpirationDate;   /*!< \var expiration date */
    float   m_RunningTotal;     /*!< \var running total of all member fees */
    Receipt m_Receipt;          /*!< \var receipt of member purchases */

};

/*!
 * \namespace std
 * \brief Used to overlaod less comparator
 */
namespace std {
/*!
 * \struct less<Member>
 * \brief The less struct
 * \details Overloads operator()
 */
template<>
struct less<Member> {
    /*!
     * \fn operator()
     * \brief Compares members by id
     * \param lhs
     * \param rhs
     * \return lhs id < rhs id
     */
    bool operator()(const Member& lhs, const Member& rhs) const {
        return lhs.Id() < rhs.Id();
    }
};
}
#endif // MEMBER_H
