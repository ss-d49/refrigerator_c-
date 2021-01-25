#ifndef FRIDGEINVENTORY_H_
#define FRIDGEINVENTORY_H_
#include <vector>
#include "foodItem.h"
#define FILEPATH "save.dat"

class fridgeInventory {
public:
    static std::vector<foodItem> createNewFridge();
    static std::vector<foodItem> openFridge();
};

#endif //FRIDGEINVENTORY_H_
