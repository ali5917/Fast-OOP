#include <iostream>
using namespace std;

class SmartDevice {
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool getStatus() = 0;

};

class LightBulb : public SmartDevice {
    private:
        bool isOn;
        int brightness;

    public:
        LightBulb() : isOn(false), brightness(0) {}
        
        void turnOn() {
            isOn = true;
            brightness = 65;
            cout << "Light Bulb is on. Brightness level = " << brightness << endl;
        }

        void turnOff() {
            isOn = false;
            brightness = 0;
            cout << "Light Bulb is off. Brightness level = " << brightness << endl;
        }

        bool getStatus() {
            return isOn; 
        }

};

class Thermostat : public SmartDevice {
    private:
        bool isOn;
        double temperature;

    public:
        Thermostat() : isOn(false), temperature(25) {}
        
        void turnOn() {
            isOn = true;
            temperature = 40;
            cout << "Thermostat is on. Temperature level = " << temperature << endl;
        }
        
        void turnOff() {
            isOn = false;
            temperature = 24;
            cout << "Thermostat is off. Temperature level = " << temperature << endl;
        }

        bool getStatus() { 
            return isOn; 
        }
};

int main() {
    LightBulb l;
    Thermostat t;
    
    l.turnOn();
    l.turnOff();
    t.turnOn();
    t.turnOff();
}