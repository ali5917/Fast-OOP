#include <iostream>
#include <string>
using namespace std;

class Currency {
    protected:
        float amount;
        string currencyCode; 
        string currencySymbol;
        float exchangeRate;
    
    public:
        Currency(double a, string c, string s, double r) : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(r) {}
        
        virtual double convertToBase() {
            cout << "Converting to base" << endl;
            return 0;
        }
        
        virtual double convertTo(Currency &targetCurrency) {
            return amount * exchangeRate/targetCurrency.exchangeRate;
        }
        
        virtual void displayDetails() {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

class Dollar: public Currency { 
    public:
        Dollar(double a) : Currency(a, "USD", "$", 1.0) {}
        
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

class Euro: public Currency {
    public:
        Euro(double a) : Currency(a, "EUR", "€", 1.0877) {}
        
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

class Rupee: public Currency {
    public:
        Rupee(double a) : Currency(a, "PKR", "Rs", 0.0036) {}
        
        double convertToBase() override {
            cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
            return amount * exchangeRate;
        }
        
        void displayDetails() override {
            cout << "Currency Symbol: " << currencySymbol << endl << "Currency Code: " << currencyCode << endl << "Amount: " << amount << endl << "Exchange Rate: " << exchangeRate << endl << endl;
        }
};

int main() {
    Dollar dollar(100);
    Euro euro(150);
    Rupee rupee(100);
    
    dollar.displayDetails();
    euro.displayDetails();
    rupee.displayDetails();
    
    cout << "100 USD -> EUR: " << dollar.convertTo(euro) << " EUR" << endl;
    cout << "100 EUR -> PKR: " << euro.convertTo(rupee) << " PKR" << endl;
 
    return 0;
}