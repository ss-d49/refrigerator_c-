#ifndef FRIDGEINVENTORY_H_
#define FRIDGEINVENTORY_H_
#include "foodItem.h"

#include <fstream>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include <vector>
#include <yaml-cpp/yaml.h>

using namespace std;
using namespace rapidjson;

class fridgeInventory {
public:
  fridgeInventory();
  void createNewFridge();
  void addItem(foodItem foodItem);
  vector<foodItem> getFridge();
  void setFridge(vector<foodItem> foodItems);
  void openFridge();
  void displayContents();
  void write();

private:
  vector<foodItem> _fridge;
  string _filepath;
};
#endif // FRIDGEINVENTORY_H_
