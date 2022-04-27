#include "itemlist.h"

ItemList::ItemList() {

}

ItemList::~ItemList() {
    this->m_ItemList.clear();
}

ItemList::ItemList(const std::vector<std::pair<Item*, int>>& itemList) {
    for(size_t i = 0; i < itemList.size(); i++) {
        *(this->m_ItemList[i].first) = *(itemList[i].first);
        this->m_ItemList[i].second = itemList[i].second;
    }
}

bool ItemList::insert(Item* item, const int& quantity) {
    Item* temp = this->find(item->name());

    if(temp != nullptr) {
        this->m_ItemList[indexOf(temp->name())].second += quantity;
        return false;
    }
    else { 
        //if item doesn't exist, create a new item pointer and add it to the item list
        this->m_ItemList.push_back(std::make_pair(item, quantity));

        //return true (item added)
        return true;
    }
}

/*
bool ItemList::remove(const QString& name, const int& quantity) {
    Item* temp = this->find(name);

    if(temp == nullptr) {
        //if item doesn't exist in item list
        //if item exists but the quantity to be removed > item quantity, return false (quantity not removed)
        return false;
    }
    else {
        //remove quantity

        //return true (quantity removed)
        return true;
    }
}
*/

bool ItemList::removeItem(const QString& name) {
    if(find(name) == nullptr) {
        return false;
    }

    for(auto& x : this->m_ItemList) {
        if((x.first)->name() == name) {
            std::pair<Item*, int> temp = x;
            this->m_ItemList.erase(std::find(this->m_ItemList.begin(), this->m_ItemList.end(), temp));
            return true;
        }
    }
    return false;
}

Item* ItemList::find(const QString& name) {
    for(auto& x : this->m_ItemList) {
        if((x.first)->name() == name) {
            return x.first;
        }
    }

    return nullptr;
}

int ItemList::size() const {
    return this->m_ItemList.size();
}

std::vector<std::pair<Item*, int>> ItemList::itemList() const {
    return this->m_ItemList;
}

int ItemList::indexOf(const QString& name) {
    for(size_t i = 0; i < this->m_ItemList.size(); i++) {
        if((this->m_ItemList[i].first)->name() == name) {
            return i;
        }
    }
    return -1;
}
