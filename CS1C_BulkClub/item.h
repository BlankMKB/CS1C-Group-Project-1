#ifndef ITEM_H
#define ITEM_H
#include <QString>


class Item {
private:
    QString m_Name; /*!< \var item name */
    float m_Price; /*!< \var item price */
    int m_Quantity; /*!< \var item quantity */

public:
    /*!
     * \brief default constructor/
     */
    Item();

    /*!
     * \brief overloaded constructor
     * \param name: QString
     * \param price: float
     * \param quantity: int
     */
    Item(const QString&, const float&, const int&);

    /*!
     * \brief copy constructor
     * \param otherItem: Item
     */
    Item(const Item&);

    /*!
     * \brief returns name
     * \return name: QString
     */
    QString name() const;

    /*!
     * \brief returns price
     * \return price: float
     */
    float price() const;

    /*!
     * \brief returns item quantity
     * \return quantity: int
     */
    int quantity() const;

    /*!
     * \brief sets item name
     * \param name: QString
     */
    void setName(const QString&);

    /*!
     * \brief sets item price
     * \param price: float
     */
    void setPrice(const float&);

    /*!
     * \brief addQuantity
     */
    void addQuantity(const int&);

    /*!
     * \brief setQuantity
     */
    void setQuantity(const int&);

};

namespace std {
template<>
struct less<Item> {
    bool operator()(const Item& one, const Item& two) const {
        return one.name() < two.name();
    }
};

template<>
struct less<Item*> {
    bool operator()(const Item* one, const Item* two) const {
        return one->name() < two->name();
    }
};
}
#endif // ITEM_H
