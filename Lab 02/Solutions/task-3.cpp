#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

struct Employee {
    int employeeID;
    string name;
    string department;
    int salary;
};

void displayEmployees (Employee *employees, int numEmployees) {
    cout << "\nAll Employees\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nID: " << employees[i].employeeID << "  Name: " << employees[i].name << "\nDepartment: " << employees[i].department << "  Salary: " << employees[i].salary << endl;
    }
    cout << "\n";
}

void searchEmployee (Employee *employees, int numEmployees) {
    int thisID, found = 0;
    cout << "\nEnter Employee ID: ";
    cin  >> thisID;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == thisID) {
            cout << "\nID: " << employees[i].employeeID << "  Name: " << employees[i].name << "\nDepartment: " << employees[i].department << "  Salary: " << employees[i].salary << endl;
            found = 1;
            break;
        }
    }

    if (!found) {
        cout << "No Matching Employee ID Found!" << endl;
    }
}

int main () {
    // Employee Management System
    int numEmployees;
    
    cout << "Enter the number of Employees: ";
    cin >> numEmployees;

    Employee *employees = new Employee[numEmployees];
    
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "   ID: ";
        cin >> employees[i].employeeID;
        cout << "   Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "   Department: ";
        getline(cin, employees[i].department);
        cout << "   Salary: ";
        cin >> employees[i].salary;
    }

    while (true) {
        int choice = 0;
        
        cout << "\nChoose your Operation:";
        cout << "\n   1. Display Employees";
        cout << "\n   2. Search Employee";
        cout << "\n   3. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 3) {
            cout << "\nExiting...";
            break;
        }

        switch (choice) {
            case 1:
                displayEmployees(employees, numEmployees);
                break;
            case 2:
                searchEmployee(employees, numEmployees);
                break; 
            default:
                cout << "Please Enter a valid Choice!\n"; 
                break;
        }
    }

    delete[] employees;

    return 0;
}