#ifndef FOODITEM_H_
#define FOODITEM_H_

#include <string>
using namespace std;

class foodItem {
private:
  string _itemName;
  int _expiryDate;

public:
  foodItem(string itemName, int expiryDate);
  string getItemName() const;
  int getExpiryDate() const;
  void setItemName(string itemName);
  void setExpiryDate(int expiryDate);
};

#endif /*FOODITEM_H_*/