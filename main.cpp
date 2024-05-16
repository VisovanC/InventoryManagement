#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define MAX_PRODUCTS 100
#define FILENAME "products.txt"

struct Product {
    std::string name;
    std::string category;
    int quantity;
};

Product products[MAX_PRODUCTS];

void read_products() {
    std::ifstream file(FILENAME);
    if (!file) {
        std::cout << "File does not exist." << std::endl;
        return;
    }
    int i = 0;
    while (file >> products[i].name >> products[i].category >> products[i].quantity && i < MAX_PRODUCTS) {
        i++;
    }
    file.close();
}

void save_products() {
    std::ofstream file(FILENAME);
    if (!file) {
        std::cout << "File does not exist." << std::endl;
        return;
    }
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name.empty()) {
            continue;
        }
        file << products[i].name << " " << products[i].category << " " << products[i].quantity << std::endl;
    }
    file.close();
}

void add_product() {
    std::string name, category;
    int quantity;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter category: ";
    std::cin >> category;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name.empty()) {
            products[i].name = name;
            products[i].category = category;
            products[i].quantity = quantity;
            break;
        }
    }
}

void update_product() {
    std::string name;
    int quantity;
    std::cout << "Enter name: ";
    std::cin >> name;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name == name) {
            std::cout << "Enter new quantity: ";
            std::cin >> quantity;
            products[i].quantity = quantity;
            std::cout << "Product updated." << std::endl;
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

void delete_product() {
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name == name) {
            products[i] = Product();
            std::cout << "Product deleted." << std::endl;
            return;
        }
    }
    std::cout << "Product not found." << std::endl;
}

void search_products() {
    std::string keyword;
    std::cout << "Enter keyword: ";
    std::cin >> keyword;
    std::cout << "Search results=============================================" << std::endl;
    std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Category" << std::setw(10) << "Quantity" << std::endl;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name.empty()) {
            continue;
        }
        if (products[i].name == keyword || products[i].category == keyword) {
            std::cout << std::left << std::setw(20) << products[i].name << std::setw(15) << products[i].category << std::setw(10) << products[i].quantity << std::endl;
        }
    }
}

void display_products() {
    std::cout << "=============================================" << std::endl;
    std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Category" << std::setw(10) << "Quantity" << std::endl;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name.empty()) {
            continue;
        }
        std::cout << std::left << std::setw(20) << products[i].name << std::setw(15) << products[i].category << std::setw(10) << products[i].quantity << std::endl;
    }
}

void display_low_quantity_products() {
    std::cout << "=============================================" << std::endl;
    std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Category" << std::setw(10) << "Quantity" << std::endl;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name.empty()) {
            continue;
        }
        if (products[i].quantity < 10) {
            std::cout << std::left << std::setw(20) << products[i].name << std::setw(15) << products[i].category << std::setw(10) << products[i].quantity << std::endl;
        }
    }
}

int main() {
    read_products();
    int option;
    do {
        std::cout << "===========================\n";
        std::cout << "Inventory Management System\n";
        std::cout << "===========================\n";
        std::cout << "1. Add product\n";
        std::cout << "2. Update product\n";
        std::cout << "3. Delete product\n";
        std::cout << "4. Search products\n";
        std::cout << "5. Display all products\n";
        std::cout << "6. Display low quantity products\n";
        std::cout << "7. Save products\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter option: ";
        std::cin >> option;
        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                update_product();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                search_products();
                break;
            case 5:
                display_products();
                break;
            case 6:
                display_low_quantity_products();
                break;
            case 7:
                save_products();
                break;
            case 0:
                std::cout << "Goodbye, my friend." << std::endl;
                break;
            default:
                std::cout << "Wrong option." << std::endl;
        }
    } while (option != 0);
    return 0;
}
