#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
        string name;
        float salary;

        Employee (string n, float s) : name (n), salary (s) {}

        virtual void displayDetails () {
            cout << "Employee Details:\n";
            cout << "\nName: " << name;
            cout << "\nSalary: " << salary << " PKR";
        }
};

class Manager : public Employee {
    public:
        float bonus;

        Manager (string n, float s, float b) : Employee (n, s), bonus (b) {}

        void displayDetails () override {
            cout << "Manager Details:\n";
            cout << "\nName: " << name;
            cout << "\nSalary: " << salary;
            cout << "\nBonus: " << bonus << " PKR";
        }
};

int main () {
    Manager ali ("Ali", 98000.45, 1500.70);
    ali.displayDetails();
    
    return 0;
}