#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

class ItemList {
private:
    std::vector<std::pair<Item*, int>> m_ItemList; /*!< \var list of items in the format: std::vector<std::pair<Item*, int>> */

private:
    /*!
     * \brief helper function that returns the index of a particular item
     * \return index: int
     */
    int indexOf(const QString&);



public:
    /*!
     * \brief default constructor
     */
    ItemList();

    /*!
     * \brief copy constructor
     * \param otherItemList: ItemList
     */
    ItemList(const ItemList&);

    /*!
     * \brief overloaded constructor using
     * \param otherItemList: std::vector<std::pair<Item*, int>>
     */
    ItemList(const std::vector<std::pair<Item*, int>>&);

    /*!
     * destructor
     */
    ~ItemList();

    /*!
     * \brief returns the item list
     * \return itemList: std::vector<std::pair<Item*, int>>
     */
    std::vector<std::pair<Item*, int>> itemList() const;

    /*!
     * \brief returns the size of the item list
     * \return size: size_t
     */
    size_t size() const;

    /*!
     * \brief inserts item into item list
     */
    void insert(Item*, const int&);

    /*!
     * \brief inserts item into inventory
     */
    void insertInventory(Item*, const int&);

    /*!
     * \brief removes item
     * \return true if removed successfully, false otherwise
     */
    bool removeItem(const QString&);

    /*!
     * \brief returns the pointer to an item if it exists, null otherwise
     * \return pItem: Item*
     */
    Item* find(const QString&);

    /*!
     * \brief sorts item list by item
     */
    void sort();

    /*!
     * \brief returns the item list in string format: for database use
     * \return itemListString: QString
     */
    QString itemListString() const;
};

#endif // ITEMLIST_H
