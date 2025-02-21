#include <iostream>
#include <string>

using namespace std;

class Battery {
private:
    int capacity; 

public:
    Battery(int capacity) : capacity(capacity) {}

    int getCapacity() const {
        return capacity;
    }

    void display() const {
        cout << "Battery Capacity: " << capacity << " mAh" << endl;
    }
};

class Smartphone {
private:
    string model;
    string brand;
    Battery battery; 

public:
    Smartphone(const string& model, const string& brand, int batteryCapacity)
        : model(model), brand(brand), battery(batteryCapacity) {}

    void displayDetails() const {
        cout << "Smartphone Details:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        battery.display(); 
    }
};

int main() {

    Smartphone myPhone("iPhone 13", "Apple", 3200);
    myPhone.displayDetails();

    Smartphone yourPhone("Galaxy S22", "Samsung", 4000);
    yourPhone.displayDetails();

    return 0;
}