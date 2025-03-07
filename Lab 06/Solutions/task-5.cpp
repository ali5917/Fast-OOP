#include <iostream>
#include <string>
using namespace std;

class Device {
    public:
        int deviceID;
        bool status;

        Device (int d, bool s) : deviceID(d), status (s) {}

        virtual void displayDetails () {
            cout << "\nDevice Details:\n";
            cout << "\nDevice ID: " << deviceID;
            cout << "\nStatus: " << (status ? "In Stock" : "Out of Stock") << endl;
        }
};

class SmartPhone : virtual public Device {
    public:
        float screenSize;

        SmartPhone (int d, bool s, float size) : Device (d, s), screenSize (size) {}

        void displayDetails () override {
            cout << "\nSmart Phone Details:\n";
            cout << "\nDevice ID: " << deviceID;
            cout << "\nStatus: " << (status ? "In Stock" : "Out of Stock");
            cout << "\nScreen Size: " << screenSize << " inches" << endl;
        }
};

class SmartWatch : virtual public Device {
    public:
        bool heartRateMonitor;

        SmartWatch (int d, bool s, bool h) : Device (d, s), heartRateMonitor (h) {}

        void displayDetails () override {
            cout << "\nSmart Watch Details:\n";
            cout << "\nDevice ID: " << deviceID;
            cout << "\nStatus: " << (status ? "In Stock" : "Out of Stock");
            cout << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available") << endl;
        }
};

class SmartWearable : public SmartPhone, public SmartWatch {
    public:
        int stepCounter;

        SmartWearable (int d, bool s, float size, bool h, int step) : Device (d, s), SmartPhone (d, s, size), SmartWatch(d, s, h), stepCounter(step) {}

        void displayDetails () override {
            cout << "\nSmart Wearable Details:\n";
            cout << "\nDevice ID: " << deviceID;
            cout << "\nStatus: " << (status ? "In Stock" : "Out of Stock");
            cout << "\nScreen Size: " << screenSize << " inches";
            cout << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available");
            cout << "\nSteps: " << stepCounter  << endl;
        }
};

int main () {
    SmartWearable device1 (101, true, 5, true, 20);
    device1.displayDetails();

    return 0;
}