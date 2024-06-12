#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "item.h"

class Supermarket {
private:
    std::vector<Item*> items;
    int next_id;

public:
    Supermarket();

    void load_data(const std::string& filename);
    void view_sales();
    void save_sales(const std::string& filename);
    void save_data(const std::string& filename);
    void add_item(const std::string& name, int quantity, int price, bool perishable);
    Item* find_item_by_id(int id);
    void purchase_item(int id);
    void view_items();
    void edit_item(int id);
};

#endif // SUPERMARKET_H
