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

/*!
 * \class InventoryManager
 * \brief The InventoryManager Class
 * \details This class stores member information into a database.
 * \paragraph The database, by default, is set to store persistent
 * changes. In order to reset the database, use the
 * function ResetWithTextFile(). You
 * must use the overloaded constructor with a specified
 * path. Main initializes the inventory database if and
 * only if the database is empty. To manually reset the
 * database, call DeleteAllItems() then InitializeInventoryDB().
 * \note This class deletes the default copy constructor and operator=() function.
 */
class InventoryManager {
// constructors
public:
    /*!
     * \fn InventoryManager()
     * \brief Overloaded constructor
     * \param path: QString
     */
    InventoryManager(const QString& path);

    /*!
     * \fn ~InventoryManager()
     * \brief Destructor
     */
    ~InventoryManager();

// accessors
public:
    /*!
     * \fn InitializeInventoryDB()
     * \brief Initializes database
     * \return true if initialized correctly, false otherwise
     */
    bool InitializeInventoryDB();

    /*!
     * \fn ItemByName(const QString&)
     * \brief Item by name
     * \param name: QString
     * \return item: Item
     */
    Item ItemByName(const QString& name) const;

    /*!
     * \fn AllItems()
     * \brief Returns a vector of item pointers
     * \return inventory: std::vector<Item*>
     */
    ItemList AllItems() const;

    /*!
     * \fn ItemCount()
     * \brief Returns how many items are in the database
     * \return count: size_t
     */
    size_t ItemCount() const;

    /*!
     * \brief checks if database is empty
     * \return true if empty, false otherwise
     */
    bool Empty() const;

// mutators
public:
    /*!
     * \fn AddItem(const Item*)
     * \brief Adds item into database
     * \param item: Item*
     * \return true if added correctly, false otherwise
     */
    bool AddItem(const Item* item);

    /*!
     * \fn UpdateItem(const Item&)
     * \brief Updates Item in database
     * \param item: Item
     * \return true if updated correctly, false otherwise
     */
    bool UpdateItem(const Item& item);

    /*!
     * \fn DeleteItemByName(const QString&)
     * \brief Deletes member by id from database
     * \param name: QString
     * \return true if deleted correctly, false otherwise
     */
    bool DeleteItemByName(const QString& name);

    /*!
     * \fn DeleteAllItems()
     * \brief deletes all members from the database
     */
    void DeleteAllItems();

    /*!
     * \fn PrintInventoryDB()
     * \brief for debug purposes: prints all member data
     */
    void PrintInventoryDB() const;

    /*!
     * \fn ResetWithTextFile()
     * \brief reset with text file
     */
    void ResetWithTextFile();

// deleted functions
public:
    /*!
     * \fn InventoryManager(const InventoryManager&)
     * \brief InventoryManager
     * \param other
     */
    InventoryManager(const InventoryManager& other) = delete;

    /*!
     * \fn operator=(const InventoryManager&)
     * \brief operator=
     * \param other
     * \return
     */
    InventoryManager& operator=(const InventoryManager& other) = delete;

// helper functions
private:
    /*!
     * \fn ItemFromRecord(const QSql Record)
     * \brief Helper function that returns item from record
     * \param record: QSqlRecord
     * \return item: Item
     */
    Item ItemFromRecord(const QSqlRecord& record) const;

// variables
private:
    QSqlDatabase m_Database;    /*!< \var database object: QSqlDatabase */
    Parser       m_FileParser;  /*!< \var parser object: Parser */

};

#endif // INVENTORYMANAGER_H
