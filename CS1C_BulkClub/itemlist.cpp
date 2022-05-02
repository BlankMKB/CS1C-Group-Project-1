#include "itemlist.h"

//==========================================PRIVATE MEMBER FUNCTIONS==========================================

//indexof
int ItemList::indexOf(const QString& name) {
    for(size_t i = 0; i < this->m_ItemList.size(); i++) {
        if((this->m_ItemList[i].first)->name() == name) {
            return i;
        }
    }
    return -1;
}

//=============================================================================================================


//===========================================PUBLIC MEMBER FUNCTIONS===========================================

//constructor
ItemList::ItemList() {

}

//copy constructor
ItemList::ItemList(const ItemList& other) {
    for(const auto& x : other.itemList()) {
        Item* temp = new Item(*x.first);
        this->m_ItemList.push_back(std::make_pair(temp, x.second));
    }
    //this->m_ItemList = other.itemList();
}

//overloaded constructor
ItemList::ItemList(const std::vector<std::pair<Item*, int>>& itemList) {
    for(size_t i = 0; i < itemList.size(); i++) {
        *(this->m_ItemList[i].first) = *(itemList[i].first);
        this->m_ItemList[i].second = itemList[i].second;
    }
}

//destructor
ItemList::~ItemList() {
    this->m_ItemList.clear();
}

//itemList
std::vector<std::pair<Item*, int>> ItemList::itemList() const {
    return this->m_ItemList;
}

//size
size_t ItemList::size() const {
    return this->m_ItemList.size();
}

//insert
void ItemList::insert(Item* item, const int& quantity) {
    this->m_ItemList.push_back(std::make_pair(item, quantity));
}

void ItemList::insertInventory(Item* item, const int& quantity) {
    for(auto& tempItem : this->m_ItemList) {
        if(tempItem.first->name() == item->name()) {
            tempItem.second += quantity;
            return;
        }
    }
    insert(item, quantity);
}

//removeItem
bool ItemList::removeItem(const QString& name) {
    //find item
    if(find(name) == nullptr) {
        //item doesn't exist
        return false;
    }

    //for each item in the item list
    for(auto& item : this->m_ItemList) {
        //if name matches
        if((item.first)->name() == name) {
            //remove item
            this->m_ItemList.erase(std::find(this->m_ItemList.begin(), this->m_ItemList.end(), item));
            return true;
        }
    }
    //item doesn't exist
    return false;
}

//find
Item* ItemList::find(const QString& name) {
    //for each item in item list
    for(auto& item : this->m_ItemList) {
        //if the item names match
        if((item.first)->name() == name) {
            return item.first;
        }
    }

    //item doesn't exist
    return nullptr;
}

//sort
void ItemList::sort() {
    std::sort(this->m_ItemList.begin(), this->m_ItemList.end());
}

//itemListString
QString ItemList::itemListString() const {
    if(this->m_ItemList.empty()) {
        return "";
    }

    QString str = "";
    QString name, price, quantity;
    for(size_t i = 0; i < this->m_ItemList.size(); i++) {
        //parse temp item
        Item* temp = (this->m_ItemList[i].first);
        name = temp->name();
        price = QString::number(temp->price());
        quantity = QString::number(this->m_ItemList[i].second);

        //add to string
        if(i + 1 == this->m_ItemList.size()) {
            str += name + ", " + price + ", " + quantity;
            break;
        }
        else {
            str += name + ", " + price + ", " + quantity + ", ";
        }

        name = "";
        price = "";
        quantity = "";
    }
    return str;
}

//=============================================================================================================
