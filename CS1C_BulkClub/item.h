#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item {
private:
    QString _name; /*!< \var item name */
    float _price; /*!< \var item price */
    int _quantity; /*!< \var item quantity */

public:
    /*!
     * \brief Item default constructor
     */
    Item() : _name(""), _price(0), _quantity(0) {

    }

    /*!
     * \brief Item overloaded constructor
     * \param name: QString
     * \param price: float
     * \param quantity: int
     */
    Item(const QString& name, const float& price, const int& quantity) : _name(name), _price(price), _quantity(quantity) {

    }

    /*!
     * \brief returns name
     * \return name: QString
     */
    QString name() const {
        return this->_name;
    }

    /*!
     * \brief returns price
     * \return price: float
     */
    float price() const {
        return this->_price;
    }

    /*!
     * \brief returns quantity
     * \return quantity: int
     */
    int quantity() const {
        return this->_quantity;
    }
};

#endif // ITEM_H
