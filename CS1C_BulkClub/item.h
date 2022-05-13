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
    QString Name() const;

    /*!
     * \brief returns price
     * \return price: float
     */
    float Price() const;

    /*!
     * \brief returns item quantity
     * \return quantity: int
     */
    int Quantity() const;

    /*!
     * \brief sets item name
     * \param name: QString
     */
    void SetName(const QString&);

    /*!
     * \brief sets item price
     * \param price: float
     */
    void SetPrice(const float&);

    /*!
     * \brief addQuantity
     */
    void AddQuantity(const int&);

    /*!
     * \brief setQuantity
     */
    void SetQuantity(const int&);

};

namespace std {
template<>
struct less<Item> {
    bool operator()(const Item& one, const Item& two) const {
        return one.Name() < two.Name();
    }
};

template<>
struct less<Item*> {
    bool operator()(const Item* one, const Item* two) const {
        return one->Name() < two->Name();
    }
};
}
#endif // ITEM_H
