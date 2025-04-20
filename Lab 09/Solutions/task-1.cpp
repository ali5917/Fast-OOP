#include <iostream>
using namespace std;

class Vehicle {
    protected:
        string model;
        double rate;

    public:
        Vehicle(string m, double r) : model(m), rate(r) {}
        
        virtual double getDailyRate() = 0;
        virtual void displayDetails() = 0;

};

class Car : public Vehicle {
    public:
        Car(string m, double r) : Vehicle(m,r) {}
        
        double getDailyRate() { 
            return (rate * 1.1); 
        }
        
        void displayDetails() {
            cout << "Model: " << model << endl << "Rate: " << getDailyRate() << endl;
        }
        
};

class Bike : public Vehicle {
    public:
        Bike(string m, double r) : Vehicle(m, r) {}
        
        double getDailyRate() { 
            return rate; 
        }
        
        void displayDetails() {
            cout << "Model: " << model << endl << "Rate: " << getDailyRate() << endl;
        }
        
};

int main() {

    Bike b("Unique", 10.99);
    b.displayDetails();
    Car c("Sonata", 20.34);
    c.displayDetails();
}