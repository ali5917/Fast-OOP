#include <iostream>
#include <string>
using namespace std;

class Account {
    public:
        int accountNumber;
        float balance;

        Account (int a, float b) : accountNumber(a), balance(b) {}

        virtual void displayDetails() {
            cout << "\nAccount Details:";
            cout << "\nAccount Number: " << accountNumber;
            cout << "\nBalance: " << balance << " PKR\n";
        }
};

class SavingsAccount : public Account {
    public:
        float interestRate;

        SavingsAccount (int a, float b, float i) : Account  (a, b), interestRate(i) {}

        void displayDetails () override {
            cout << "\nSavings Account Details:\n";
            cout << "\nAccount Number: " << accountNumber;
            cout << "\nBalance: " << balance << " PKR";
            cout << "\nInterest Rate: " << interestRate << "%" << endl;
        }
};

class CheckingAccount : public Account {
    public:
        float overdraftLimit;

        CheckingAccount (int a, float b, float o) : Account (a, b), overdraftLimit(o) {}

        void displayDetails () override {
            cout << "\nChecking Account Details:\n";
            cout << "\nAccount Number: " << accountNumber;
            cout << "\nBalance: " << balance << " PKR";
            cout << "\nOverdraft Limit: " << overdraftLimit << " PKR" << endl;
        }
};

int main () {
    SavingsAccount acc1 (1012, 98910.49, 4.5);
    CheckingAccount acc2 (1015, 47910.67, 50000.0);
    acc1.displayDetails();
    acc2.displayDetails();


    return 0;
}