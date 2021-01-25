#include <iostream>
#include <fstream>
#include <vector>
#include "ObjectIO.h"

void ObjectIO::WriteObjectToFile(std::vector<foodItem>& fridge, char filepath[]) {
    std::ofstream outfile;
    outfile.open(filepath, std::ios::out);
    for(foodItem f: fridge) {
        outfile << f.getItemName() << ';' << f.getExpiryDate() << std::endl;
    }
    outfile.close();
}

std::vector<foodItem> ObjectIO::ReadObjectFromFile(char filepath[]) {
    std::ifstream i = std::ifstream{filepath};
    std::vector<foodItem> fridge;
    std::string line = {};

    while( i >> line) {
        auto pos = line.find_first_of(';');
        fridge.push_back( foodItem( std::string{line, 0, pos}, atoi( std::string{line, pos+1}.c_str()) ) );
    }
    return fridge;
}