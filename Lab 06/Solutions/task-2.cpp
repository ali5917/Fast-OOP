#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
        string brand;
        int speed;

        Vehicle (string b, int s) : brand (b), speed (s) {}

        virtual void displayDetails () {
            cout << "Vehicle Details:\n";
            cout << "\nBrand: " << brand;
            cout << "\nSpeed: " << speed << " kmph" << endl;
        }
};

class Car : public Vehicle {
    public:
        int seats;

        Car (string b, int s, int seats) : Vehicle (b, s), seats (seats) {}

        void displayDetails () override {
            cout << "Car Details:\n";
            cout << "\nBrand: " << brand;
            cout << "\nSpeed: " << speed << " kmph";
            cout << "\nSeats: " << seats << endl;
        }
};

class ElectricCar : public Car {
    public:
        int batteryLife;

        ElectricCar (string b, int s, int seats, int battery) : Car (b, s, seats), batteryLife(battery) {}

        void displayDetails () override {
            cout << "Electric Car Details:\n";
            cout << "\nBrand: " << brand;
            cout << "\nSpeed: " << speed << " kmph";
            cout << "\nSeats: " << seats;
            cout << "\nBattery Life: " << batteryLife << " miles" << endl;
        }
};

int main () {
    ElectricCar myCar ("Tesla", 250, 4, 350000);
    myCar.displayDetails();

    return 0;
}