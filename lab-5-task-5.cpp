#include <iostream>
#include <string>

using namespace std;

class TourGuide {
public:
    string name;
    int yearsOfExperience;
    string specialization;
    TourGuide* next; 

    TourGuide(const string& name, int yearsOfExperience, const string& specialization)
      : name(name), yearsOfExperience(yearsOfExperience), specialization(specialization), next(nullptr) {}

    void display() const {
        cout << "Name: " << name << ", Experience: " << yearsOfExperience
             << " years, Specialization: " << specialization << endl;
    }
};

class TravelAgency {
public:
    string name;
    TourGuide* tourGuides; 

    TravelAgency(const string& name): name(name), tourGuides(nullptr) {}

    void assignGuide(TourGuide* guide) {
        if (tourGuides == nullptr) {
            tourGuides = guide;
        } else {
            TourGuide* current = tourGuides;
            while (current->next!= nullptr) {
                current = current->next;
            }
            current->next = guide;
        }
    }

    void displayDetails() const {
        cout << "Travel Agency: " << name << endl;
        cout << "Tour Guides:" << endl;
        if (tourGuides == nullptr) {
            cout << "No tour guides currently assigned." << endl;
        } else {
            TourGuide* current = tourGuides;
            while (current!= nullptr) {
                current->display();
                current = current->next;
            }
        }
    }

    ~TravelAgency() { 
        TourGuide* current = tourGuides;
        while (current!= nullptr) {
            TourGuide* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {

    TourGuide* guide1 = new TourGuide("Alice Johnson", 5, "Historical Tours");
    TourGuide* guide2 = new TourGuide("Bob Williams", 10, "Nature Treks");
    TourGuide* guide3 = new TourGuide("Eva Garcia", 7, "City Sightseeing");

    TravelAgency agency1("Adventure Tours");
    TravelAgency agency2("Cultural Experiences");

    agency1.assignGuide(guide1);
    agency1.assignGuide(guide2);
    agency2.assignGuide(guide3);
    agency2.assignGuide(guide1); 
    agency1.displayDetails();
    cout << endl;
    agency2.displayDetails();

    return 0;
}