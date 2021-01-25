#ifndef OBJECTIO_H_
#define OBJECTIO_H_
#include "foodItem.h"
class ObjectIO {
public:
    static void WriteObjectToFile(std::vector<foodItem>& fridge, char filepath[]);
    static std::vector<foodItem> ReadObjectFromFile(char filepath[]);
};

#endif /*OBJECTIO_H_*/