#include <iostream>
using namespace std;

class PaymentMethod {
    public:
        virtual void processPayment(double amount) = 0;

};

class CreditCard : public PaymentMethod {
    private:
        string cardNumber;

    public:
        CreditCard(string c) : cardNumber(c) {}
       
        void processPayment(double amount) {
            if (amount < 0 || amount > 5000) {
                cout << "Invalid Amount" << endl;
                return;
            }

            cout << "Credit Card Transaction successfull for " << amount << endl;
        }
};

class DebitCard : public PaymentMethod { 
    private:
        double balance;

    public:
        DebitCard(double b = 4000) : balance(b) {}
        
        void processPayment(double amount) {
            if(amount > balance) {
                cout << "Amount > Balance. Transaction unsuccefull" << endl;
                return;
            } else if(amount < 0) {
                cout << "Amount < 0. Transaction unsuccessful" << endl;
                return;
            }

            balance -= amount;
            cout << "Debit Card Transaction successfull for " << amount << "\nUpdated Balance: " << balance << endl;
        }

};

int main() {
    CreditCard cr("021-325-203");
    DebitCard dr(10000);

    dr.processPayment(500);
    cr.processPayment(2000);
    dr.processPayment(20000);
    cr.processPayment(5000);
}