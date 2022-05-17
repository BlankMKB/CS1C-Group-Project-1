#include "item.h"

//overloaded constructor
Item::Item(const QString& name, const float& price, const int& quantity) : m_Name(name),
                                                                           m_Price(price),
                                                                           m_Quantity(quantity) { }

//copy constructor
Item::Item(const Item* other) {
    m_Name = other->Name();
    m_Price = other->Price();
    m_Quantity = other->Quantity();
}





//name
QString Item::Name() const { return m_Name; }

//price
float Item::Price() const { return m_Price; }

//quantity
int Item::Quantity() const { return m_Quantity; }






//set name
void Item::SetName(const QString& name) { m_Name = name; }

//set price
void Item::SetPrice(const float& price) { m_Price = price; }

//add quantity
void Item::AddQuantity(const int& quantity) { m_Quantity += quantity; }

//set quantity
void Item::SetQuantity(const int& quantity) { m_Quantity = quantity; }


