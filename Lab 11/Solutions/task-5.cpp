#include <iostream>
using namespace std;

class InsufficientFundsException: public exception {
    private:
        double deficit;
        string message;

    public:
        InsufficientFundsException (float d) : deficit (d) {
            message = "InsufficientFundsException - Deficit: $" + to_string(deficit);
        } 
        const char* what () const noexcept override {
            return message.c_str();
        }
};

template <typename T>
class BankAccount {
    public:
        T balance;
        BankAccount(T b) : balance (b) {
            cout << "Balance: $" << balance << endl;
        }

        void widthdraw (T amount) {
            if (amount > balance) {
                throw InsufficientFundsException(amount - balance);
            } else {
                balance -= amount;
                cout << "Withdrawn $" << amount << endl;
            }
        }
};

int main () {
    BankAccount <float> account (500.0);
    try {
        account.widthdraw(600.0);
    }
    catch (const InsufficientFundsException &e) {
        cout << "Withdraw $600: " << e.what() << endl;
    } 
}
