#include <iostream>

using namespace std;

class car {

public:
    int regisNo;
    string modelName;
    string owner;

    car(){};

    car(car& c1, string owner){

        c1.owner = owner;
    }

    void Data(int reg, string model, string ownerp) {

        regisNo = reg;
        modelName = model;
        owner = ownerp;
    }

    void display() {
        
        cout << "Name of owner is = " << owner << endl;
        cout << "Model name is = " << modelName << endl;
        cout << "Registration no is = " << regisNo << endl;
    }
};

int main() {

    car c1;
    c1.Data(2021026, "Rebirth" , "Shayan");
    c1.display();
    car c2(c1, "Shariq");
    c1.display();

}