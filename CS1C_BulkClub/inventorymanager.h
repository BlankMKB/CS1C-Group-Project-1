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
    Item ItemFromRecord(const QSqlRecord&) const;

    /*!
     * \brief checks if database is empty
     * \return true if empty, false otherwise
     */
    bool Empty() const;

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
    bool InitializeInventoryDB();

    /*!
     * \brief item by name
     * \return item: Item
     */
    Item ItemByName(const QString&) const;

    /*!
     * \brief returns a vector of item pointers
     * \return inventory: std::vector<Item*>
     */
    ItemList AllItems() const;

    /*!
     * \brief returns how many items are in the database
     * \return count: unsigned
     */
    unsigned ItemCount() const;

    /*!
     * \brief adds item into database
     * \return true if added correctly, false otherwise
     */
    bool AddItem(const Item*);

    /*!
     * \brief updates Item in database
     * \return true if updated correctly, false otherwise
     */
    bool UpdateItem(const Item&);
    /*!
     * \brief deletes member by id from database
     * \return true if deleted correctly, false otherwise
     */
    bool DeleteItemByName(const QString&);

    /*!
     * \brief deletes all members from the database
     */
    void DeleteAllItems();

    /*!
     * \brief for debug purposes: prints all member data
     */
    void PrintInventoryDB() const;
};

#endif // INVENTORYMANAGER_H
