#include "itemlist.h"

//copy constructor
ItemList::ItemList(const ItemList& other) {
    for(const auto& item : other.itemList()) {
        Item* temp = new Item(*item);
        m_ItemList.push_back(temp);
    }
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





//empty
bool ItemList::empty() const { return m_ItemList.size() == 0; }

//itemList
std::vector<Item*> ItemList::itemList() const { return m_ItemList; }

//size
size_t ItemList::size() const { return m_ItemList.size(); }

//itemListString
QString ItemList::ItemListString() const {
    if(m_ItemList.empty()) {
        return "";
    }

    QString str = "";
    QString name, price, quantity;
    for(size_t i = 0; i < m_ItemList.size(); i++) {
        //parse temp item
        Item* temp = m_ItemList[i];
        name = temp->Name();
        price = QString::number(temp->Price());
        quantity = QString::number(temp->Quantity());

        //add to string
        if(i + 1 == m_ItemList.size()) {
            str += name + ", " + price + ", " + quantity + ", ";
            break;
        }
        else {
            str += name + ", " + price + ", " + quantity + ", ";
        }

        name = price = quantity = "";
    }
    return str;
}





//insert
void ItemList::Insert(Item* item) {  m_ItemList.push_back(item); }


//insert inventory
void ItemList::InsertInventory(Item* item) {
    for(auto& tempItem : m_ItemList) {
        if(tempItem->Name() == item->Name() && tempItem->Price() == item->Price()) {
            tempItem->AddQuantity(item->Quantity());
            return;
        }
    }

    Insert(item);
}

//removeItem
bool ItemList::RemoveItem(const QString& name) {
    //item doesn't exist
    if(Find(name) == nullptr) { return false; }

    //for each item in the item list
    for(auto& item : m_ItemList) {
        //if name matches
        if(item->Name() == name) {
            //remove item
            m_ItemList.erase(std::find(m_ItemList.begin(), m_ItemList.end(), item));
            return true;
        }
    }

    //item doesn't exist
    return false;
}

//find
Item* ItemList::Find(const QString& name) {
    //for each item in item list
    for(auto& item : m_ItemList) {
        //if the item names match
        if(item->Name() == name) { return item; }
    }

    //item doesn't exist
    return nullptr;
}





//begin
std::vector<Item*>::const_iterator ItemList::begin() const { return m_ItemList.begin(); }

//end
std::vector<Item*>::const_iterator ItemList::end() const { return m_ItemList.begin(); }

//at
Item* ItemList::at(const int& index) const { return m_ItemList[index]; }

//operator[]
Item* ItemList::operator[](const int& index) { return m_ItemList[index]; }

//operator[] const
Item* ItemList::operator[](const int& index) const { return m_ItemList[index]; }

//sort
void ItemList::sort() {
    std::sort(m_ItemList.begin(), m_ItemList.end(), std::less<Item*>());
}

//indexof
int ItemList::IndexOf(const QString& name) {
    for(size_t i = 0; i < m_ItemList.size(); i++) {
        if((m_ItemList[i])->Name() == name) {
            return i;
        }
    }
    return -1;
}
