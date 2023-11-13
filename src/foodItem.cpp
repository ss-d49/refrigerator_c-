#include "foodItem.h"

foodItem::foodItem(string itemName, int expiryDate) {
    this->_itemName = itemName;
    this->_expiryDate = expiryDate;
}

string foodItem::getItemName() const {
    return this->_itemName;
}

void foodItem::setItemName(string itemName) {
    this->_itemName = itemName;
}

int foodItem::getExpiryDate() const {
    return this->_expiryDate;
}

void foodItem::setExpiryDate(int expiryDate) {
    this->_expiryDate = expiryDate;
}
