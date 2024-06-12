#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    int id;
    std::string name;
    int quantity;
    int price;
    bool perishable;
};

#endif // ITEM_H
