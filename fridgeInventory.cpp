#include "fridgeInventory.h"
#include "ObjectIO.h"

std::vector<foodItem> fridgeInventory::createNewFridge() {
    std::vector<foodItem> fridge;
    return fridge;
}

std::vector<foodItem> fridgeInventory::openFridge() {
    std::vector<foodItem> fridge = ObjectIO::ReadObjectFromFile((char *)FILEPATH);
    return fridge;
}