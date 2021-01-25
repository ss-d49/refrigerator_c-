#ifndef FOODITEM_H_
#define FOODITEM_H_

#include <string>

class foodItem {
private:
    std::string itemName;
    int expiryDate;

public:
    std::string getItemName() const;
    int getExpiryDate() const;
    void setItemName(std::string itemName);
    void setExpiryDate(int expiryDate);
    foodItem (std::string itemName,int expiryDate);
};

#endif /*FOODITEM_H_*/