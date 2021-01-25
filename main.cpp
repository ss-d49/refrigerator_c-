#include <iostream>
#include "fridgeInventory.h"
#include "ObjectIO.h"

static void addToFridge(std::vector<foodItem>& fridge) {
    while (true) {
        char foodItemName[32];
        std::cout << "Enter Food Item Name: ";
        std::cin >> foodItemName;

        int date;
        std::cout << "Enter Expiry Date: ";
        std::cin >> date;

        fridge.emplace_back(foodItem(foodItemName, date));
        std::cout << "Add More Items?: Y / N";
        char input;
        std::cin >> input;
        if (input == 'y') {
        }
        else if (input == 'n') {
            ObjectIO::WriteObjectToFile(fridge, (char *)FILEPATH);
            break;
        }
    }
}
static void editFridge(std::vector<foodItem>& fridge) {
    for (foodItem f : fridge) {
        std::cout << f.getItemName() + " " << f.getExpiryDate();
        std::cout << "Is this the Item?: Y / N";
        char input;
        std::cin >> input;
        if (input == 'y') {
            std::cout << "Edit Name or Expiry Date?: N / E";
            std::cin >> input;
            if (input == 'n') {
                char foodItemName[32];
                std::cout << "Enter Food Item Name: ";
                std::cin >> foodItemName;
                f.setItemName(foodItemName);
            } else if (input == 'e') {
                int date;
                std::cout << "Enter Expiry Date: ";
                std::cin >> date;
                f.setExpiryDate(date);
            }
        }
        else if (input == 'n') {
                std::cout << f.getItemName() + " " << f.getExpiryDate();
        }
    }
}
static void displayFridgeContents(std::vector<foodItem>& fridge) {
    for (foodItem f : fridge)
        std::cout << f.getItemName() << ' ' << f.getExpiryDate() << std::endl;
}

int main() {
    std::cout << "Create New Fridge or Open Existing?: N / O";
    char input;
	std::cin >> input;
    std::vector<foodItem> fridge;
    if (input == 'n') {
        fridge = fridgeInventory::createNewFridge();
        addToFridge(fridge);
    }
    else if (input == 'O'){
        fridge = fridgeInventory::openFridge();
    }
    std::cout << "Edit Fridge Contents?: Y / N";
	std::cin >> input;
    if (input == 'y') {
        std::cout << "Add Items to Fridge?: Y / N";
		std::cin >> input;
        if (input == 'y') {
            addToFridge(fridge);
        }
        else if (input == 'n') {
            std::cout << "Edit Items in Fridge?: Y / N";
			std::cin >> input;
            if (input == 'y') {
                editFridge(fridge);
            }
        }
    }

    std::cout << "Display Fridge Contents?: Y / N";
	std::cin >> input;
    if (input == 'y') {
        displayFridgeContents(fridge);
    }
    else if (input == 'n') {

    }
}
