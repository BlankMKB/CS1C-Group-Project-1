#include "item.h"

//default constructor
Item::Item() : m_Name(""), m_Price(0), m_Quantity(0) {

}

//copy constructor
Item::Item(const Item& other) {
    this->m_Name = other.name();
    this->m_Price = other.price();
    this->m_Quantity = other.quantity();
}

//overloaded constructor
Item::Item(const QString& name, const float& price, const int& quantity) : m_Name(name), m_Price(price), m_Quantity(quantity) {

}

//name
QString Item::name() const {
    return this->m_Name;
}

//price
float Item::price() const {
    return this->m_Price;
}

//quantity
int Item::quantity() const {
    return this->m_Quantity;
}

//set name
void Item::setName(const QString& name) {
    this->m_Name = name;
}

//set price
void Item::setPrice(const float& price) {
    this->m_Price = price;
}

//add quantity
void Item::addQuantity(const int& quantity) {
    this->m_Quantity += quantity;
}

//set quantity
void Item::setQuantity(const int& quantity) {
    this->m_Quantity = quantity;
}


