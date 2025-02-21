#include <iostream>
#include <string>

using namespace std;

class Professor {
public:
    string name;
    string department;
    Professor* next; 

    Professor(const string& name, const string& department) : name(name), department(department), next(nullptr) {}

    void display() const {
        cout << "Name: " << name << ", Department: " << department << endl;
    }
};

class University {
public:
    string name;
    Professor* professors; 

    University(const string& name) : name(name), professors(nullptr) {}

    void addProfessor(const string& name, const string& department) {
        Professor* newProfessor = new Professor(name, department);
        if (professors == nullptr) {
            professors = newProfessor;
        } else {
            Professor* current = professors;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newProfessor;
        }
    }

    void displayDetails() const {
        cout << "University Name: " << name << endl;
        cout << "Professors:" << endl;
        if (professors == nullptr) {
            cout << "No professors currently employed." << endl;
        } else {
            Professor* current = professors;
            while (current != nullptr) {
                current->display();
                current = current->next;
            }
        }
    }

    ~University() { 
        Professor* current = professors;
        while (current != nullptr) {
            Professor* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    University fast("FAST University");

    fast.addProfessor("Dr. Ayesha Khan", "Computer Science");
    fast.addProfessor("Dr. Ali Raza", "AI & DS");
    fast.addProfessor("Dr. Sana Tariq", "Software Engineering");

    fast.displayDetails();

    return 0;
}