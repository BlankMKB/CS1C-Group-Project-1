#include "itemlist.h"

//==========================================PRIVATE MEMBER FUNCTIONS==========================================

//indexof
int ItemList::indexOf(const QString& name) {
    for(size_t i = 0; i < m_ItemList.size(); i++) {
        if((m_ItemList[i])->name() == name) {
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
        Item* temp = new Item(*x);
        m_ItemList.push_back(temp);
    }
    //m_ItemList = other.itemList();
}

//overloaded constructor
ItemList::ItemList(const std::vector<Item*>& itemList) {
    for(size_t i = 0; i < itemList.size(); i++) {
        *(m_ItemList[i]) = *(itemList[i]);
    }
}

//destructor
ItemList::~ItemList() {
    m_ItemList.clear();
}

// vector functoins


std::vector<Item*>::const_iterator ItemList::begin() const {
    return m_ItemList.begin();
}

std::vector<Item*>::const_iterator ItemList::end() const {
    return m_ItemList.begin();
}

Item* ItemList::at(const int& index) const {
    return m_ItemList[index];
}

Item*& ItemList::operator[](const int& index) const {
    Item* item = m_ItemList[index];
    return item;
}

//itemList
std::vector<Item*> ItemList::itemList() const {
    return m_ItemList;
}

//size
size_t ItemList::size() const {
    return m_ItemList.size();
}

//insert
void ItemList::insert(Item* item) {
    m_ItemList.push_back(item);
}

void ItemList::insertInventory(Item* item) {
    for(auto& tempItem : m_ItemList) {
        if(tempItem->name() == item->name()) {
            tempItem->addQuantity(item->quantity());
            return;
        }
    }
    insert(item);
}

bool ItemList::empty() const {
    return m_ItemList.size() == 0;
}

//removeItem
bool ItemList::removeItem(const QString& name) {
    //find item
    if(find(name) == nullptr) {
        //item doesn't exist
        return false;
    }

    //for each item in the item list
    for(auto& item : m_ItemList) {
        //if name matches
        if(item->name() == name) {
            //remove item
            m_ItemList.erase(std::find(m_ItemList.begin(), m_ItemList.end(), item));
            return true;
        }
    }
    //item doesn't exist
    return false;
}

//find
Item* ItemList::find(const QString& name) {
    //for each item in item list
    for(auto& item : m_ItemList) {
        //if the item names match
        if(item->name() == name) {
            return item;
        }
    }

    //item doesn't exist
    return nullptr;
}

//itemListString
QString ItemList::itemListString() const {
    if(m_ItemList.empty()) {
        return "";
    }

    QString str = "";
    QString name, price, quantity;
    for(size_t i = 0; i < m_ItemList.size(); i++) {
        //parse temp item
        Item* temp = m_ItemList[i];
        name = temp->name();
        price = QString::number(temp->price());
        quantity = QString::number(temp->quantity());

        //add to string
        if(i + 1 == m_ItemList.size()) {
            str += name + ", " + price + ", " + quantity + ", ";
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

void ItemList::sort() {
    std::sort(m_ItemList.begin(), m_ItemList.end(), std::less<Item*>());
}
//=============================================================================================================
