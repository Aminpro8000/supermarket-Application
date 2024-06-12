#include "supermarket.h"

Supermarket::Supermarket() : next_id(0) {}

void Supermarket::load_data(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Item* item = new Item();
        std::string data;
        std::getline(iss, data, ',');
        item->id = std::stoi(data);
        std::getline(iss, item->name, ',');
        std::getline(iss, data, ',');
        item->quantity = std::stoi(data);
        std::getline(iss, data, ',');
        item->price = std::stoi(data);
        std::getline(iss, data);
        item->perishable = (data == "1");
        items.push_back(item);
    }
    if (!items.empty()) {
        next_id = items.back()->id + 1;
    }
}

void Supermarket::view_sales() {
    std::cout << "------------------Sales------------------" << std::endl;
    std::cout << "Here are all the sales made:" << std::endl;
    for (const auto& item : items) {
        int total_sales = (item->quantity * item->price);
        std::cout << "id: " << item->id << ", name: " << item->name << ", quantity: " << item->quantity << ", total sales: " << total_sales << std::endl;
        std::cout << "--------------------" << std::endl;
    }
}

void Supermarket::save_sales(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& item : items) {
        int total_sales = (item->quantity * item->price);
        file << "id: " << item->id << ", name: " << item->name << ", quantity: " << item->quantity << ", total sales: " << total_sales << '\n';
    }
}

void Supermarket::save_data(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& item : items) {
        file << item->id << ',' << item->name << ',' << item->quantity << ',' << item->price << ',' << item->perishable << '\n';
    }
}

void Supermarket::add_item(const std::string& name, int quantity, int price, bool perishable) {
    Item* item = new Item();
    item->id = next_id++;
    item->name = name;
    item->quantity = quantity;
    item->price = price;
    item->perishable = perishable;
    items.push_back(item);
}

Item* Supermarket::find_item_by_id(int id) {
    for (auto& item : items) {
        if (item->id == id) {
            return item;
        }
    }
    return nullptr;
}

void Supermarket::purchase_item(int id) {
    Item* item_to_purchase = find_item_by_id(id);
    if (item_to_purchase) {
        if (item_to_purchase->quantity > 0) {
            std::cout << "Pay " << item_to_purchase->price << " at checkout counter." << std::endl;
            item_to_purchase->quantity--;
            std::cout << "Item successfully purchased." << std::endl;
        } else {
            std::cout << "Item out of stock." << std::endl;
        }
    } else {
        std::cout << "Item not found." << std::endl;
    }
}

void Supermarket::view_items() {
    std::cout << "------------------View Items------------------" << std::endl;
    std::cout << "The number of items in the inventory are: " << items.size() << std::endl;
    if (items.empty()) {
        std::cout << "No items available in the supermarket." << std::endl;
    } else {
        std::cout << "Here are all the items available in the supermarket:" << std::endl;
        for (const auto& item : items) {
            std::cout << "id: " << item->id << ", name: " << item->name << ", quantity: " << item->quantity << ", price: " << item->price << ", perishable: " << (item->perishable ? "yes" : "no") << std::endl;
            std::cout << "--------------------" << std::endl;
        }
    }
}

void Supermarket::edit_item(int id) {
    Item* item_to_edit = find_item_by_id(id);
    if (item_to_edit) {
        std::cout << "Editing item with ID: " << item_to_edit->id << std::endl;
        std::cout << "Enter new name: ";
        std::getline(std::cin, item_to_edit->name);
        std::cout << "Enter new quantity: ";
        std::cin >> item_to_edit->quantity;
        std::cout << "Enter new price: ";
        std::cin >> item_to_edit->price;
        std::cout << "Is the item perishable? (yes/no): ";
        std::string perishable_str;
        std::cin >> perishable_str;
        item_to_edit->perishable = (perishable_str == "yes" || perishable_str == "y");
        std::cout << "Item has been successfully edited." << std::endl;
        std::cin.ignore();  // Ignore newline character left in the buffer
    } else {
        std::cout << "Item not found." << std::endl;
    }
}

