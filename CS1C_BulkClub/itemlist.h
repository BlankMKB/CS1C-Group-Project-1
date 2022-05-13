#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

class ItemList {
private:
    std::vector<Item*> m_ItemList; /*!< \var list of items in the format: std::vector<std::pair<Item*, int>> */

private:
    /*!
     * \brief helper function that returns the index of a particular item
     * \return index: int
     */
    int IndexOf(const QString&);

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
    ItemList(const std::vector<Item*>&);

    /*!
     * destructor
     */
    ~ItemList();

    // vector wrapper functions
    std::vector<Item*>::const_iterator begin() const;

    std::vector<Item*>::const_iterator end() const;

    Item* at(const int&) const;

    Item*& operator[](const int&) const;

    void sort();

    bool empty() const;

    /*!
     * \brief returns the item list
     * \return itemList: std::vector<std::pair<Item*, int>>
     */
    std::vector<Item*> itemList() const;

    /*!
     * \brief returns the size of the item list
     * \return size: size_t
     */
    size_t size() const;

    /*!
     * \brief inserts item into item list
     */
    void Insert(Item*);

    /*!
     * \brief inserts item into inventory
     */
    void InsertInventory(Item*);

    /*!
     * \brief removes item
     * \return true if removed successfully, false otherwise
     */
    bool RemoveItem(const QString&);

    /*!
     * \brief returns the pointer to an item if it exists, null otherwise
     * \return pItem: Item*
     */
    Item* Find(const QString&);

    /*!
     * \brief returns the item list in string format: for database use
     * \return itemListString: QString
     */
    QString ItemListString() const;

};

#endif // ITEMLIST_H
