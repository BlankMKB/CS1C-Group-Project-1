#include "item.h"

Item::Item() : m_Name(""), m_Price(0), m_Quantity(0) {

}

Item::Item(const QString& name, const float& price, const int& quantity) : m_Name(name), m_Price(price), m_Quantity(quantity) {

}

QString Item::name() const {
    return this->m_Name;
}

float Item::price() const {
    return this->m_Price;
}

int Item::quantity() const {
    return this->m_Quantity;
}

void Item::setName(const QString& name) {
    this->m_Name = name;
}

void Item::setPrice(const float& price) {
    this->m_Price = price;
}

void Item::setQuantity(const int& quantity) {
    this->m_Quantity = quantity;
}

void Item::addQuantity(const int& quantity) {
    this->m_Quantity += quantity;
}
