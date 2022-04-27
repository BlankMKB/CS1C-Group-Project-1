#include "item.h"

Item::Item() : m_Name(""), m_Price(0) {

}

Item::Item(const QString& name, const float& price) : m_Name(name), m_Price(price) {

}

QString Item::name() const {
    return this->m_Name;
}

float Item::price() const {
    return this->m_Price;
}

void Item::setName(const QString& name) {
    this->m_Name = name;
}

void Item::setPrice(const float& price) {
    this->m_Price = price;
}
