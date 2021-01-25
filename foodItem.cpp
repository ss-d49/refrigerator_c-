#include "foodItem.h"

std::string foodItem::getItemName() const {
    return this->itemName;
}

int foodItem::getExpiryDate() const {
    return this->expiryDate;
}

void foodItem::setItemName(std::string itemName) {
    this->itemName = itemName;
}

void foodItem::setExpiryDate(int expiryDate) {
    this->expiryDate = expiryDate;
}

foodItem::foodItem (std::string itemName,int expiryDate) {
    this->itemName = itemName;
    this->expiryDate = expiryDate;
}