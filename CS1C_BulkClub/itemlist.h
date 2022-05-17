#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

/*!
 * \class ItemList
 * \brief The ItemList Class
 * \details This class stores a collection of Items
 * \paragraph This class is a vector wrapper class. The item list
 * itself is a vector of Item pointers. This class allows
 * for ranged-based for loops due to the vector
 * wrapper functions included. It includes a
 * const_iterator begin() and end(), Item* at(),
 * Item* operator[] and operator[] const, and provides
 * an overloaded sort() function that sorts items by name.
 * \note This class has a defaulted default constructor.
 */
class ItemList {
// constructors
public:
    /*!
     * \fn ItemList(const Itemlist&)
     * \brief Copy constructor
     * \param otherItemList: ItemList
     */
    ItemList(const ItemList& other);

    /*!
     * \fn ItemList(const std::vector<Item*>&)
     * \brief overloaded constructor using
     * \param otherItemList: std::vector<std::pair<Item*, int>>
     */
    ItemList(const std::vector<Item*>& other);

    /*!
     * \fn ~ItemList()
     * \brief Destructor
     */
    ~ItemList();

// accessors
public:
    /*!
     * \fn empty()
     * \return true if empty, false otherwise
     */
    bool empty() const;

    /*!
     * \fn itemList()
     * \brief Returns the item list
     * \return itemList: std::vector<std::pair<Item*, int>>
     */
    std::vector<Item*> itemList() const;

    /*!
     * \fn size()
     * \brief Returns the size of the item list
     * \return size: size_t
     */
    size_t size() const;

    /*!
     * \fn ItemListString();
     * \brief Returns the item list in string format: for database use
     * \return itemListString: QString
     */
    QString ItemListString() const;

// mutators
public:
    /*!
     * \fn Insert(Item*)
     * \brief Inserts item into item list
     * \param item: Item*
     */
    void Insert(Item* item);

    /*!
     * \fn InsertInventory
     * \brief Updates quantity if item exists, adds item otherwise
     * \param item: Item*
     */
    void InsertInventory(Item* item);

    /*!
     * \fn RemoveItem(const QString&)
     * \brief Removes item
     * \return true if removed successfully, false otherwise
     */
    bool RemoveItem(const QString& name);

    /*!
     * \fn Find(const QString&)
     * \brief Returns the pointer to an item if it exists, null otherwise
     * \return p_Item: Item*
     */
    Item* Find(const QString& name);

// vector iterator wrappers
public:
    /*!
     * \fn begin()
     * \brief begin
     * \return const_iterator
     */
    std::vector<Item*>::const_iterator begin() const;

    /*!
     * \fn end()
     * \brief end
     * \return const_iterator
     */
    std::vector<Item*>::const_iterator end() const;

    /*!
     * \fn at(const int&)
     * \brief at
     * \param index: int
     * \return item: Item*
     */
    Item* at(const int& index) const;

    /*!
     * \fn operator[](const int&)
     * \brief operator[]
     * \param index: int
     * \return item: Item*&
     */
    Item* operator[](const int& index);

    /*!
     * \fn operator[](const int&)
     * \brief operator[] const
     * \param index: int
     * \return item: Item*&
     */
    Item* operator[](const int& index) const;


    /*!
     * \fn sort()
     * \brief Sorts vector by name
     */
    void sort();

// defaulted constructors
public:
    /*!
     * \fn ItemList()
     * \brief Default constructor
     */
    ItemList() = default;

// helper functions
private:
    /*!
     * \fn IndexOf(const QString&)
     * \brief helper function that returns the index of a particular item given name
     * \param name: QString
     * \return index: int
     */
    int IndexOf(const QString& name);

// variables
private:
    std::vector<Item*> m_ItemList; /*!< \var list of items in the format: std::vector<std::pair<Item*, int>> */


};

#endif // ITEMLIST_H
