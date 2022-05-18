#include "receipt.h"

//receipt
std::vector<std::pair<Date, ItemList>> Receipt::receipt() const { return m_Receipt; }

//size
size_t Receipt::size() const { return m_Receipt.size(); }

//empty
bool Receipt::Empty() const { return m_Receipt.size() == 0; }

//receipt by date
ItemList Receipt::ReceiptByDay(const Date& key) {
    ItemList empty;
    for(auto& [date, itemlist] : m_Receipt) {
        if(date == key) {
            return itemlist;
        }
    }
    return empty;
}

//receipt string
QString Receipt::ReceiptString() const {
    if(m_Receipt.empty()) {
        return "";
    }

    QString str = "";
    QString date, list;
    for(size_t i = 0; i < m_Receipt.size(); i ++) {
        date = "#" + m_Receipt[i].first.DateString();
        list = m_Receipt[i].second.ItemListString();


        /*
        if(i + 1 == m_Receipt.size()) {
            str += date + ", " + list + " ";
            break;
        }
        */

        str += date + ", " + list + ", ";

        date = "";
        list = "";
    }

    return str;
}





//add item
bool Receipt::Add(const Date& day, Item* item) {
    //for each element in receip
    for(auto& x : m_Receipt) {
        //add to date
        if(x.first == day) {
            x.second.Insert(item);
            //not a new day
            return false;
        }
    }
    //else make a new item list with a new date and push it back to receipt
    ItemList temp;
    temp.Insert(item);
    m_Receipt.push_back(std::make_pair(day, temp));

    return true;
}
