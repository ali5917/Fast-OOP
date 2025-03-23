#include <iostream>
#include <string>
using namespace std;

class Account {
    protected:
        int accountNumber;
        float balance;
        string accountHolderName;
        string accountType;

    public:
        Account(int a, float b, string n, string t) : accountNumber(a), balance(b), accountHolderName(n), accountType(t) {}
        
        void deposit(float amount)  {
            balance += amount;
            cout << "Amount Deposited - Updated Balance: $" << balance << endl;
        } 
        
        virtual void withdraw(float amount) {
            if(amount > balance) {
                cout << "Cannot withdraw! Amount > Balance" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn - Updated Balance: $" << balance << endl;
            }
        }

        virtual void calculateInterest() = 0;

        virtual void printStatement() = 0;

        void getAccountInfo() {
            cout << "Account Number: " << accountNumber << endl << "Balance: " << balance << endl << "Account Holder Name: " << accountHolderName << endl << "Account Type: " << accountType << endl;
        }

};

class SavingsAccount : public Account {
    private:
        float interestRate;
        float minimumBalance;

    public:
        SavingsAccount(int a, float b, string n, string t, float i, float m) : Account(a, b, n, t), interestRate(i), minimumBalance(m) {}
        
        void calculateInterest() override {
            float interest = interestRate * (balance/100);
            cout << "Saving account interest for amount $" << balance << " is $" << interest << endl;
        }
        
        void printStatement() override {
            cout << "- Transaction History for Savings Account -" << endl;
        }
       
        void withdraw(float amount) override {
            if (amount > balance) {
                cout << "Cannot withdraw! Insufficient Balance" << endl;
            } else if (balance - amount < minimumBalance) {
                cout << "Cannot withdraw! Amount will drop below minimum balance" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn - Updated Balance: $" << balance << endl;
            }
        }
};

class FixedDepositAccount : public Account {
    private:
        float fixedInterestRate;
        string maturityDate;
    
    public:
        FixedDepositAccount(int a, float b, string n, string t, float r, string m) : Account(a, b, n, t), fixedInterestRate(r), maturityDate(m) {}
        
        void calculateInterest() override {
            float interest = fixedInterestRate * (balance/100);
            cout << "Fixed Deposit account interest for amount $" << balance << " is $" << interest << endl;
        }
        
        void printStatement() override {
            cout << "- Transaction History for Fixed Deposit Account -" << endl;
        }
        
};

class CheckingAccount : public Account {
    private:
        float overDraftLimit;
    
    public:
        CheckingAccount(int a, float b, string n, string t, float o) : Account(a, b, n, t), overDraftLimit(o) {}
        
        void calculateInterest() override {
            cout << "Checking accounts do not offer interest" << endl;
        }

        void printStatement() override {
            cout << "- Transaction History for Checking Account -"<< endl;
        }

        void withdraw(float amount) override {
            if(amount > balance + overDraftLimit) {
                cout << "Cannot withdraw! Amount is more than the (Balance + over draft limit)" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn - Updated Balance: $" << balance << endl;
            }
        }

};

int main() {
    SavingsAccount savings(1, 5000, "Ali Kashif", "Savings", 2.6, 2000);
    FixedDepositAccount fixed(2, 10000, "Ismail Silat", "Fixed Deposit", 5.0, "2028-05-22");
    CheckingAccount checking(3, 2000, "Ahmed Faraz", "Checking", 300);

    cout << "Savings Account\n\n";
    savings.getAccountInfo();
    savings.deposit(1000);
    savings.withdraw(2000);
    savings.calculateInterest();
    savings.printStatement();

    cout << "\n\nFixed Deposit Account\n\n";
    fixed.getAccountInfo();
    fixed.deposit(2000);
    fixed.withdraw(3000);
    fixed.calculateInterest();
    fixed.printStatement();

    cout << "\n\nChecking Account\n\n";
    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(3000);
    checking.calculateInterest();
    checking.printStatement();

    return 0;
}