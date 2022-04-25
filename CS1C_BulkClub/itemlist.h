#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

class ItemList {
protected:
    std::vector<Item*> m_ItemList;

protected:
    bool compare(const Item&, const Item&);

public:
    ItemList();
    ItemList(const std::vector<Item*>&);
    ~ItemList();
    bool insert(Item*, const int&);
    bool remove(const QString&, const int&);
    Item* find(const QString&);
    int size() const;
    std::vector<Item*> itemList() const;
};

#endif // ITEMLIST_H
