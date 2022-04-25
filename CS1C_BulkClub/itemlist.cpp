#include "itemlist.h"

ItemList::ItemList() {

}

ItemList::~ItemList() {
    this->m_ItemList.clear();
}

ItemList::ItemList(const std::vector<Item*>& itemList) {
    this->m_ItemList = itemList;
}

bool ItemList::insert(Item* item, const int& quantity) {
    Item* temp = this->find(item->name());

    if(temp != nullptr) {
        temp->addQuantity(quantity);
        return false;
    }
    else {
        item->setQuantity(quantity);
        //if item doesn't exist, create a new item pointer and add it to the item list
        this->m_ItemList.push_back(item);

        //return true (item added)
        return true;
    }
}

bool ItemList::remove(const QString& name, const int& quantity) {
    Item* temp = this->find(name);

    if(temp == nullptr || temp->quantity() <= quantity) {
        //if item doesn't exist in item list
        //if item exists but the quantity to be removed > item quantity, return false (quantity not removed)
        return false;
    }
    else {
        //remove quantity
        int tempQuant = temp->quantity();
        tempQuant -= quantity;
        temp->setQuantity(tempQuant);

        //return true (quantity removed)
        return true;
    }
}

Item* ItemList::find(const QString& name) {
    for(auto& x : this->m_ItemList) {
        if(x->name() == name) {
            return x;
        }
    }

    return nullptr;
}

int ItemList::size() const {
    return this->m_ItemList.size();
}

std::vector<Item*> ItemList::itemList() const {
    return this->m_ItemList;
}
