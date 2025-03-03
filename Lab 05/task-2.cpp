#include<iostream>
#include<string>
using namespace std;

class Patient {
    private:
        int id;
        string name;
        string *results;
        int numTests;         

    public:
        Patient(int i, string n, int num) : id(i), name(n), numTests(num) {
            results = new string[numTests];  
            cout << "Test results (positive/negative):" << endl;
            for (int i = 0; i < numTests; i++) {
                cout << "Test " << i + 1 << ": ";
                cin >> results[i];
            }
        }

        Patient(Patient &obj) {
            id = obj.id;
            name = obj.name;
            numTests = obj.numTests;
            results = new string[numTests];  
            for (int i = 0; i < numTests; i++) {
                results[i] = obj.results[i];  
            }
        }

        ~Patient() {
            delete[] results; 
        }

        void displayDetails() {
            cout << "\nPatient ID: " << id;
            cout << "\nName: " << name;
            cout << "\nTest Results: ";
            for (int i = 0; i < numTests; i++) {
                cout << results[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Patient patient1(12, "Ali Kashif", 3);
    patient1.displayDetails();
    Patient patient2 = patient1;  
    cout << "\nAfter Copying:\n";
    patient2.displayDetails();

    return 0;
}
