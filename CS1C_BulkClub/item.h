#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item {
private:
    QString m_Name; /*!< \var item name */
    float m_Price; /*!< \var item price */

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
    Item(const QString&, const float&);

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
     * \brief sets item name
     * \param name: QString
     */
    void setName(const QString&);

    /*!
     * \brief sets item price
     * \param price: float
     */
    void setPrice(const float&);
};

#endif // ITEM_H
