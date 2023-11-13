#include "main.h"

static void addToFridge(fridgeInventory *fridge) {
  while (true) {
    string foodItemName;
    cout << "Enter Food Item Name: ";
    cin >> foodItemName;

    int date;
    cout << "Enter Expiry Date: ";
    cin >> date;

    fridge->addItem(foodItem(foodItemName, date));

    cout << "Add More Items?: y / n";
    char input;
    cin >> input;
    if (input == 'y') {
    } else if (input == 'n') {
      fridge->write();
      break;
    }
  }
}
static void editFridge(fridgeInventory *fridge) {
  vector<foodItem> foodItems = fridge->getFridge();
  for (foodItem &f : foodItems) {
    cout << f.getItemName() + " " << f.getExpiryDate();
    cout << "Is this the Item?: y / n";
    char input;
    cin >> input;
    if (input == 'y') {
      cout << "Edit Name or Expiry Date?: N / E";
      cin >> input;
      if (input == 'n') {
        string foodItemName;
        cout << "Enter Food Item Name: ";
        cin >> foodItemName;
        f.setItemName(foodItemName);
      } else if (input == 'e') {
        int date;
        cout << "Enter Expiry Date: ";
        cin >> date;
        f.setExpiryDate(date);
      }
      cout << foodItems[0].getItemName();
      fridge->setFridge(foodItems);
    } else if (input == 'n') {
      cout << f.getItemName() + " " << f.getExpiryDate();
    }
  }
  fridge->write();
}

int main() {
  cout << "Create New Fridge or Open Existing?: n / o";
  char input;
  cin >> input;
  fridgeInventory *fridge = new fridgeInventory();
  ;
  if (input == 'n') {
    addToFridge(fridge);
  } else if (input == 'o') {
    fridge->openFridge();
  }
  cout << "Edit Fridge Contents?: y / n";
  cin >> input;
  if (input == 'y') {
    cout << "Add Items to Fridge?: y / n";
    cin >> input;
    if (input == 'y') {
      addToFridge(fridge);
    } else if (input == 'n') {
      cout << "Edit Items in Fridge?: y / n";
      cin >> input;
      if (input == 'y') {
        editFridge(fridge);
      }
    }
  }

  cout << "Display Fridge Contents?: y / n";
  cin >> input;
  if (input == 'y') {
    fridge->displayContents();
  } else if (input == 'n') {
    exit(0);
  }
}