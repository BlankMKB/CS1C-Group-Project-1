#ifndef RECEIPT_H
#define RECEIPT_H

#include "itemlist.h"
#include "date.h"

class Receipt {
private:
    std::vector<std::pair<Date, ItemList>> m_Receipt;

public:
    /*!
     * \brief default constructor
     */
    Receipt();

    /*!
     * \brief destructor
     */
    ~Receipt();

    /*!
     * \brief returns receipt in vector form
     * \return receipt: std::vector<std::pair<Date, ItemList>>
     */
    std::vector<std::pair<Date, ItemList>> receipt() const;

    /*!
     * \brief returns the size of the receipt
     * \return size: size_t
     */
    size_t size() const;

    /*!
     * \brief returns receipt on a given date
     * \param date: Date
     * \return receipt: ItemList
     */
    ItemList receiptByDay(const Date&);

    /*!
     * \brief adds item to receipt on a given date
     * \param purchaseDate: Date
     * \param pItem :Item*
     * \param quantity: int
     */
    void add(const Date&, Item*, const int&);

    /*!
     * \brief returns the receipt in string format: for database use
     * \return receiptString: QString
     */
    QString receiptString() const;
};

#endif // RECEIPT_H
