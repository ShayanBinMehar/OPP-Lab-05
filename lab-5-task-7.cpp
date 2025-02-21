#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100; 

struct Product {
    int id;
    string name;
    double price;
};

void addProduct(Product products[], int& numProducts) {
    if (numProducts < MAX_PRODUCTS) {
        cout << "Enter product ID: ";
        cin >> products[numProducts].id;
        cin.ignore(); 
        cout << "Enter product name: ";
        getline(cin, products[numProducts].name);
        cout << "Enter product price: ";
        cin >> products[numProducts].price;
        numProducts++;
    } else {
        cout << "Inventory is full. Cannot add more products." << endl;
    }
}

void sortProductsByPrice(Product products[], int numProducts) {
    for (int i = 0; i < numProducts - 1; i++) {
        for (int j = 0; j < numProducts - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void searchProductByName(const Product products[], int numProducts) {
    string searchName;
    cout << "Enter product name to search: ";
    cin.ignore(); 
    getline(cin, searchName);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].name == searchName) {
            cout << "Product Found:\n";
            cout << "ID: " << products[i].id << ", Name: " << products[i].name
                 << ", Price: $" << products[i].price << endl;
            return; 
        }
    }

    cout << "Product not found." << endl;
}

void displayInventory(const Product products[], int numProducts) {
    cout << "Inventory:\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "ID: " << products[i].id << ", Name: " << products[i].name
             << ", Price: $" << products[i].price << endl;
    }
}


int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;

    addProduct(inventory, numProducts);
    addProduct(inventory, numProducts);
    addProduct(inventory, numProducts);

    cout << "\nUnsorted Inventory:\n";
    displayInventory(inventory, numProducts);

    sortProductsByPrice(inventory, numProducts);

    cout << "\nSorted Inventory (by price):\n";
    displayInventory(inventory, numProducts);

    searchProductByName(inventory, numProducts);

    return 0;
}