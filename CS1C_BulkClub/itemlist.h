#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

class ItemList {
protected:
    std::vector<std::pair<Item*, int>> m_ItemList;

protected:
    int indexOf(const QString&);
    bool compare(const Item&, const Item&);

public:
    ItemList();
    ItemList(const std::vector<std::pair<Item*, int>>&);
    ~ItemList();
    bool insert(Item*, const int&);
    //bool remove(const QString&, const int&);
    Item* find(const QString&);
    int size() const;
    std::vector<std::pair<Item*, int>> itemList() const;
    bool removeItem(const QString&);
};

#endif // ITEMLIST_H
