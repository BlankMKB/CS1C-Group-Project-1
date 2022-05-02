#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <cmath>
#include "member.h"
#include "parser.h"
#define NUM_COLUMNS 3

class InventoryManager {
private:
    QSqlDatabase m_Database; /*!< \var database object */
    Parser m_FileParser; /*!< \var parser object */

private:
    //Item parseItem(const QString&) const;

    Item itemFromRecord(const QSqlRecord&, int&) const;

    /*!
     * \brief checks if database is empty
     * \return true if empty, false otherwise
     */
    bool empty() const;

public:
    /*!
     * \brief overloaded constructor
     * \param path: QString
     */
    InventoryManager(const QString&);

    /*!
     * \brief destructor
     */
    ~InventoryManager();

    /*!
     * \brief initializes database
     * \return true if initialized correctly, false otherwise
     */
    bool initialize();

    /*!
     * \brief item by name
     * \return item: Item
     */
    Item itemByName(const QString&) const;

    /*!
     * \brief returns a vector of item pointers
     * \return inventory: std::vector<Item*>
     */
    ItemList allItems() const;

    /*!
     * \brief returns how many items are in the database
     * \return count: unsigned
     */
    unsigned itemCount() const;

    /*!
     * \brief adds item into database
     * \return true if added correctly, false otherwise
     */
    bool addItem(const Item&, const int&);

    /*!
     * \brief updates Item in database
     * \return true if updated correctly, false otherwise
     */
    bool updateItem(const Item&, const int&);
    /*!
     * \brief deletes member by id from database
     * \return true if deleted correctly, false otherwise
     */
    bool deleteItemByName(const QString&);

    /*!
     * \brief deletes all members from the database
     */
    void deleteAllItems();

    /*!
     * \brief for debug purposes: prints all member data
     */
    void print() const;
};

#endif // INVENTORYMANAGER_H
