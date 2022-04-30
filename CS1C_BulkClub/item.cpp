#include "item.h"

//default constructor
Item::Item() : m_Name(""), m_Price(0) {

}

//copy constructor
Item::Item(const Item& other) {
    this->m_Name = other.name();
    this->m_Price = other.price();
}

//overloaded constructor
Item::Item(const QString& name, const float& price) : m_Name(name), m_Price(price) {

}

//name
QString Item::name() const {
    return this->m_Name;
}

//price
float Item::price() const {
    return this->m_Price;
}

//set name
void Item::setName(const QString& name) {
    this->m_Name = name;
}

//set price
void Item::setPrice(const float& price) {
    this->m_Price = price;
}
