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
     * \brief Item default constructor/
     */
    Item();

    /*!
     * \brief Item overloaded constructor
     * \param name: QString
     * \param price: float
     * \param quantity: int
     */
    Item(const QString&, const float&, const int&);

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
     * \brief returns quantity
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
     * \brief sets item quantity
     * \param quantity: int
     */
    void setQuantity(const int&);
};

#endif // ITEM_H
