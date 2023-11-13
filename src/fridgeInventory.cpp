#include "fridgeInventory.h"

fridgeInventory::fridgeInventory() {
    YAML::Node config = YAML::LoadFile("config.yaml");

    if (config["fridge_location"]) {
        this->_filepath = config["fridge_location"].as<string>();
    }
    else {
        cout << "No config.yaml found! Using default fridge location of data.json." << endl;
        this->_filepath = "data.json";
    }
}

void fridgeInventory::createNewFridge() {
    this->_fridge.clear();
}

void fridgeInventory::addItem(foodItem foodItem) {
    this->_fridge.emplace_back(foodItem);
}

vector<foodItem> fridgeInventory::getFridge() {
    return this->_fridge;
}

void fridgeInventory::setFridge(vector<foodItem> foodItems) {
    this->_fridge = foodItems;
}

void fridgeInventory::openFridge() {
    this->createNewFridge();
    ifstream ifs = ifstream{this->_filepath};
    IStreamWrapper isw { ifs };
    Document ents {};
    ents.ParseStream( isw );

    for (auto& v : ents["foodItems"].GetArray())
    {
        this->addItem(foodItem(v["itemName"].GetString(), v["expiryDate"].GetInt()));
    }
}

void fridgeInventory::displayContents() {
    for (foodItem f : this->_fridge)
        cout << f.getItemName() << ' ' << f.getExpiryDate() << endl;
}

void fridgeInventory::write() {
    std::ofstream outfile;
    outfile.open(this->_filepath, std::ios::out);
    
    Document ents;
    ents.SetObject();
    Value tests(kArrayType);
    Value val(kObjectType);
    Document::AllocatorType& allocator = ents.GetAllocator();
    for(foodItem f: this->_fridge) {
        Value obj(kObjectType);
        val.SetString(f.getItemName().c_str(), static_cast<SizeType>(f.getItemName().length()), allocator);
        obj.AddMember("itemName", val, allocator);
        obj.AddMember("expiryDate", f.getExpiryDate(), allocator);
        tests.PushBack(obj, allocator);
    }
    ents.AddMember("foodItems", tests, allocator);
    OStreamWrapper osw { outfile };
    PrettyWriter<OStreamWrapper> writer { osw };
    ents.Accept( writer );
}
