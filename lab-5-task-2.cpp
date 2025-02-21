#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    int id;
    string name;
    int* testResults;
    int numResults;

public:
    Patient(int id, const string& name) : id(id), name(name), testResults(nullptr), numResults(0) {}

    Patient(const Patient& other) : id(other.id), name(other.name), numResults(other.numResults) {
        if (other.testResults != nullptr) {
            testResults = new int[numResults];
            for (int i = 0; i < numResults; ++i) {
                testResults[i] = other.testResults[i];
            }
        } else {
            testResults = nullptr;
        }
    }

    void addTestResult(int result) {
        int* temp = new int[numResults + 1];
        for (int i = 0; i < numResults; ++i) {
            temp[i] = testResults[i];
        }
        temp[numResults] = result;
        delete[] testResults;
        testResults = temp;
        numResults++;
    }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        if (testResults != nullptr) {
            for (int i = 0; i < numResults; ++i) {
                cout << testResults[i] << " ";
            }
        } else {
            cout << "None";
        }
        cout << endl;
    }

    ~Patient() {
        delete[] testResults;
    }
};

int main() {

    Patient patient1(123, "Alice");
    patient1.addTestResult(95);
    patient1.addTestResult(88);
    patient1.addTestResult(92);

    Patient patient2 = patient1; 

    cout << "Patient 1 Details:" << endl;
    patient1.display();
    cout << "\nPatient 2 Details (Copy):" << endl;
    patient2.display();

    patient1.addTestResult(85);

    cout << "\nPatient 1 Details (After Modification):" << endl;
    patient1.display();
    cout << "\nPatient 2 Details (Copy - Should be unchanged):" << endl;
    patient2.display();

    return 0;
}