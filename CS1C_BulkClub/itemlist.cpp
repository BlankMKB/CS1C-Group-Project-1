#include "itemlist.h"

ItemList::ItemList() {

}

ItemList::~ItemList() {
    this->m_ItemList.clear();
}

bool ItemList::insert(const QString& name, const float& price, const int& quantity) {
    //search for item in list
    for(auto& x : this->m_ItemList) {
        if(x->name() == name) {
            //if item already exists, add to quantity
            x->addQuantity(quantity);
            //return false (no new item added)
            return false;
        }
    }

    //if item doesn't exist, create a new item pointer and add it to the item list
    Item* item = new Item(name, price, quantity);
    this->m_ItemList.push_back(item);

    //return true (item added)
    return true;
}

bool ItemList::remove(const QString& name, const int& quantity) {
    //search for item in list
    for(auto& x : this->m_ItemList) {
        if(x->name() == name) {
            //if item exists
            if(x->quantity() <= quantity) {
                //if item exists but the quantity to be removed > item quantity, return false (quantity not removed)
                return false;
            }
            else {
                //remove quantity
                int tempQuant = x->quantity();
                tempQuant -= quantity;
                x->setQuantity(tempQuant);

                //return true (quantity removed)
                return true;
            }
        }
    }
    //if item does not exist, return false (quantity not removed)
    return false;
}

Item ItemList::at(const QString& name) {
    if(this->find(name) != nullptr) {
        return *(this->find(name));
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
