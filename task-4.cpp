#include <iostream>
#include <string>
using namespace std;

class Laptop {
    private:
        string brand;
        string model;
        string processor;
        int ram;
        int storage;
        bool switchOn;
    
    public:
        Laptop() {
            cout << "\nEnter Laptop Details:\n";
            cout << "\n   Brand: ";
            getline(cin, brand);
            cout << "\n   Model: ";
            getline(cin, model);
            cout << "\n   Processor: ";
            getline(cin, processor);
            cout << "\n   RAM: ";
            cin >> ram;
            cout << "\n   Storage: ";
            cin >> storage;
            cin.ignore();
            switchOn = false;
        }

        void turnOn () {
            if (switchOn) {
                cout << "\nLaptop Already Turned On!\n";
            } else {
                switchOn = true;
                cout << "\nLaptop Turned On!";
            }
        }

        void turnOff () {
            if (!switchOn) {
                cout << "\nLaptop Already Turned Off!\n";
            } else {
                switchOn = false;
                cout << "\nLaptop Turned Off!";
            }
        }

        void runProgram () {
            if (switchOn) {
                cout << "\nRunning a Program!\n";
            } else {
                cout << "\nLaptop is Switched Off. Program can not run!\n";
            }
        }

        void getDetails() {
            cout << "\nLaptop Specifications:\n";
            cout << "   Brand: " << brand << endl;
            cout << "   Model: " << model << endl;
            cout << "   Processor: " << processor << endl;
            cout << "   RAM: " << ram << " GB" << endl;
            cout << "   Storage: " << storage << " GB" << endl;
        }
};

int main () {
    cout << "\nBilal's Laptop";
    Laptop bilalLaptop;
    cout << "\nAyesha's Laptop";
    Laptop ayeshaLaptop;
    bilalLaptop.getDetails();
    ayeshaLaptop.getDetails();


    bilalLaptop.turnOn();
    bilalLaptop.runProgram();
    bilalLaptop.turnOff();

    return 0;
}