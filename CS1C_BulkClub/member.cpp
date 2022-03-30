#include "member.h"

Member::Member(const QString& name, const int& id, const Date& expiration) : _name(name), _id(id), _expiration(expiration) {
    this->_receipt.clear();
}

QString Member::name() const {
    return this->_name;
}

int Member::id() const {
    return this->_id;
}

Date Member::expiration() const {
    return this->_expiration;
}

std::vector<Item> Member::receipt() const {
    return this->_receipt;
}

void Member::setName(const QString& name) {
    this->_name = name;
}

void Member::setID(const int& id) {
    this->_id = id;
}

void Member::setExpiration(const Date& expiration) {
    this->_expiration = expiration;
}

bool Member::addReceiptItem(const QString& itemName, const float& itemPrice, const int& itemQuantity) {
    if(this->_receipt.size() == 10) {
        qDebug() << '\n';
        qDebug() << "*********************************************************";
        qDebug() << "Maximum menu items already reached!";
        qDebug() << '(' << itemName << ", $" << itemPrice << ", " << itemQuantity << ')';
        qDebug() << "*********************************************************";
        qDebug() << '\n';

        return false;
    }
    this->_receipt.push_back(Item(itemName, itemPrice, itemQuantity));
    return true;
}

