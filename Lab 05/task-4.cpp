#include<iostream>
#include<string>
using namespace std;

class Battery {
    private:
        int capacity;
    public:
        Battery() : capacity(1000)  { }
        Battery(int c) : capacity(c) { }
        int getCapacity() {
            return capacity;
        }
};

class SmartPhone {
    private:
        Battery battery;
        string name;
        string model;
    public:
        SmartPhone(string n, string m, int c) : name(n), model(m), battery(c) { }
        void getDetails() {
            cout << "Name: " << name << endl;
            cout << "Model: " << model << endl;
            cout << "Battery Capacity: " << battery.getCapacity() << " mAh" << endl;
        }
};

int main() {
    SmartPhone phone("Samsung", "Galaxy S24", 5000);
    phone.getDetails();
    return 0;
}