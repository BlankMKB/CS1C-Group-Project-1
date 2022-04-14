#ifndef MEMBER_H
#define MEMBER_H
#include <QString>
#include <QDebug>
#include "date.h"
#include "item.h"

class Member {
private:
    QString _name; /*!< \var member name */
    bool _type; /*!< \var member type: regular: false, executive: true */
    int _id; /*!< \var member id */
    Date _expiration; /*!< \var expiration date */
    std::vector<Item> _receipt; /*!< \var running total of all member fees that are due */

public:
    /*!
     * \brief Member overloaded constructor
     * \param name
     * \param id
     * \param expiration
     * \param receipt
     */
    Member(const QString&, const int&, const Date&);

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
     * \brief returns member receipt
     * \return receipt: std::vector<Item>
     */
    std::vector<Item> receipt() const;

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
     * \brief adds receipt item
     * \param itemName: Item
     * \param itemPrice: float
     * \return true if item was successfully added
     */
    bool addReceiptItem(const QString&, const float&, const int&);

};

#endif // MEMBER_H
