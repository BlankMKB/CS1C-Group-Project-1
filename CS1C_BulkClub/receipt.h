#ifndef RECEIPT_H
#define RECEIPT_H

#include "itemlist.h"
#include "date.h"

/*!
 * \class Receipt
 * \brief The Receipt Class
 * \details This class stores a "receipt" in the form of a vecotr of pairs.
 * \paragraph This class is a vector wrapper class. The receipt
 * itself is a vector of a pair of Dates and ItemLists.
 * This class allows for ranged-based for loops as this
 * class returns the vector of receipts itself via the receipt() function.
 * \note This class has a defaulted default constructor, copy constructor,
 *           operator=(), and default destructor.
 */
class Receipt {
// accessors
public:
    /*!
     * \fn receipt()
     * \brief Returns receipt in vector form
     * \return receipt: std::vector<std::pair<Date, ItemList>>
     */
    std::vector<std::pair<Date, ItemList>> receipt() const;

    /*!
     * \fn size()
     * \brief Returns the size of the receipt
     * \return size: size_t
     */
    size_t size() const;

    /*!
     * \fn Empty()
     * \brief Returns if receipt is empty
     * \return true if empty, false otherwise
     */
    bool Empty() const;

    /*!
     * \fn ReceiptByDay(const Date&)
     * \brief returns receipt on a given date
     * \param date: Date
     * \return receipt: ItemList
     */
    ItemList ReceiptByDay(const Date& date);

    /*!
     * \fn ReceiptString()
     * \brief Returns the receipt in string format: for database use
     * \return receiptString: QString
     */
    QString ReceiptString() const;

// mutators
public:
    /*!
     * \fn Add(const Date&, Item*)
     * \brief Adds item to receipt on a given date
     * \param purchaseDate: Date
     * \param p_Item :Item*
     * \param quantity: int
     * \return true if a new date is added, false otherwise
     */
    bool Add(const Date& purchasedDate, Item* p_Item);

// defaulted constructors
public:
    /*!
     * \fn Receipt()
     * \brief Default constructor
     */
    Receipt() = default;

    /*!
     * \fn Receipt(const Receipt&)
     * \brief Default copy constructor
     * \param other: Receipt
     */
    Receipt(const Receipt& other) = default;

    /*!
     * \fn operator=(const Receipt&)
     * \brief Default operator=()
     * \param other: Receipt
     */
    Receipt& operator=(const Receipt& other) = default;

    /*!
     * \fn ~Receipt()
     * \brief Default destructor
     */
    ~Receipt() = default;

// variables
private:
    std::vector<std::pair<Date, ItemList>> m_Receipt; /*!< \var receipt of items by purchase date: std::vector<std::pair<Date, ItemList>> */

};

#endif // RECEIPT_H
