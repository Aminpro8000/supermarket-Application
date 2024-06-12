#include "supermarket.h"

int main() {
    Supermarket supermarket;
    supermarket.load_data("items.txt");

    while (true) {
        std::cout << "Press enter to continue." << std::endl;
        std::cout << "------------------Welcome to the supermarket------------------" << std::endl;
        std::cout << "1. View items\n2. Add items for sale\n3. Purchase items\n4. View sales\n5. Edit items\n6. Exit" << std::endl;
        std::cout << "Enter the number of your choice: ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            supermarket.view_items();
        } else if (choice == "2") {
            std::cout << "------------------Add items------------------" << std::endl;
            std::cout << "To add an item fill in the form" << std::endl;
            std::string name;
            int quantity, price;
            bool perishable;
            std::cout << "Item name: ";
            std::getline(std::cin, name);
            std::cout << "Item quantity: ";
            std::cin >> quantity;
            std::cout << "Price $: ";
            std::cin >> price;
            std::cout << "Is the item perishable? (yes/no): ";
            std::string perishable_str;
            std::cin >> perishable_str;
            perishable = (perishable_str == "yes" || perishable_str == "y");
            std::cout << "Item has been successfully added." << std::endl;
            std::cin.ignore();  // Ignore newline character left in the buffer
            supermarket.add_item(name, quantity, price, perishable);
        } else if (choice == "3") {
            std::cout << "------------------Purchase items------------------" << std::endl;
            int purchase_id;
            std::cout << "Enter the ID of the item you want to purchase: ";
            std::cin >> purchase_id;
            std::cin.ignore(); // ignore newline character
            supermarket.purchase_item(purchase_id);
        } else if (choice == "4") {
            supermarket.view_sales();
        } else if (choice == "5") {
            std::cout << "------------------Edit items------------------" << std::endl;
            int edit_id;
            std::cout << "Enter the ID of the item you want to edit: ";
            std::cin >> edit_id;
            std::cin.ignore(); // ignore newline character
            supermarket.edit_item(edit_id);
        } else if (choice == "6") {
            supermarket.save_data("items.txt");
            supermarket.save_sales("sales.txt");
            std::cout << "------------------Exited------------------" << std::endl;
            break;
        } else {
            std::cout << "You entered an invalid option." << std::endl;
        }
    }

    return 0;
}
