#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <vector>

class ItemList {
private:
    std::vector<Item*> m_ItemList;

private:
    bool compare(const Item&, const Item&);

public:
    ItemList();
    ~ItemList();
    bool insert(const QString&, const float&, const int&);
    bool remove(const QString&, const int&);
    Item at(const QString&) const;
    int size() const;
    Item* find(const QString&);
    std::vector<Item*> itemList() const;
};

#endif // ITEMLIST_H
