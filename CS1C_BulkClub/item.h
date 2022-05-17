#ifndef ITEM_H
#define ITEM_H
#include <QString>

/*!
 * \class Item
 * \brief The Item Class
 * \details This class stores item information
 * \note This class has defaulted default, copy, and operator=() constructors/functions
 * \note AddQuantity(const float&) adds to the existing quantity.
 * \note SetQuantity(const float&) sets a new quantity.
 */
class Item {
// constructors
public:
    /*!
     * \fn Item(const QString&, const float&, const int&)
     * \brief Overloaded constructor
     * \param name: QString
     * \param price: float
     * \param quantity: int
     */
    Item(const QString& name, const float& price, const int& quantity);

    /*!
     * \fn Item(const Item* other)
     * \brief Copy constructor with Item*
     * \param otherItem: Item*
     */
    Item(const Item* other);

// accessors
public:
    /*!
     * \fn Name()
     * \brief Returns name
     * \return name: QString
     */
    QString Name() const;

    /*!
     * \fn Price()
     * \brief Returns price
     * \return price: float
     */
    float Price() const;

    /*!
     * \fn Quantity()
     * \brief Returns item quantity
     * \return quantity: int
     */
    int Quantity() const;

// mutators
public:
    /*!
     * \fn SetName(const QString& name)
     * \brief Sets item name
     * \param name: QString
     */
    void SetName(const QString& name);

    /*!
     * \fn SetPrice(const float&)
     * \brief Sets item price
     * \param price: float
     */
    void SetPrice(const float& price);

    /*!
     * \fn AddQuantity(const int&)
     * \brief Adds quantity
     * \param quantity: int
     */
    void AddQuantity(const int& quantity);

    /*!
     * \fn SetQuantity(const int&)
     * \brief Sets quantity
     * \param quantity: int
     */
    void SetQuantity(const int& quantity);

// defaulted constructors
public:
    /*!
     * \fn Item()
     * \brief Default constructor
     */
    Item() = default;

    /*!
     * \fn Item(const Item& other)
     * \brief Default copy constructor
     * \param otherItem: Item
     */
    Item(const Item& other) = default;

    /*!
     * \fn ~Item()
     * \brief Default destructor
     */
    ~Item() = default;

// variables
private:
    QString m_Name;     /*!< \var item name */
    float   m_Price;    /*!< \var item price */
    int     m_Quantity; /*!< \var item quantity */

};

/*!
 * \namespace std
 * \brief Used to overload less struct
 * \details Compares items by name
 */
namespace std {

/*!
 * \struct less<Item>
 * \brief The less struct
 * \details Compares two items by name
 */
template<>
struct less<Item> {
    /*!
     * \fn operator()(const Item&, const Item&)
     * \brief Overloaded operator()
     * \param lhs
     * \param rhs
     * \return lhs name < rhs name
     */
    bool operator()(const Item& lhs, const Item& rhs) const {
        return lhs.Name() < rhs.Name();
    }
};

/*!
 * \fn less<Item*>
 * \brief The less struct
 * \details Compares two item pointers by name
 */
template<>
struct less<Item*> {
    /*!
     * \fn operator()(const Item*, const Item*)
     * \param lhs
     * \param rhs
     * \return lhs name < rhs name
     */
    bool operator()(const Item* lhs, const Item* rhs) const {
        return lhs->Name() < rhs->Name();
    }
};
}
#endif // ITEM_H
