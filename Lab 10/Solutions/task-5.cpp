#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    ifstream vehiclesFile;
    vehiclesFile.open("vehicles.txt");
    if (!vehiclesFile.is_open()) {
        cout << "Error opening file!";
    }

    string thisLine;
    
    while (getline(vehiclesFile, thisLine)) {
        if (!thisLine.empty() && thisLine[0] != '/') {
            stringstream ss(thisLine);
            string type, id, name, year, extraData, certification;

            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, extraData, ',');
            getline(ss, certification);

            int integerYear = stoi(year);

            cout << "\nType: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << integerYear << ", Extra Data: " << extraData << ", Certification: " << certification << endl;

            if (type == "AutonomousCar") {
                size_t pos = extraData.find(':');
                if (pos != string::npos) {
                    string str = extraData.substr(pos + 1);
                    float swVersion = stof(str);
                    cout << "ID: " << id << ", Software Version: " << swVersion << endl;
                } 
                    
            } else if (type == "ElectricVehicle") {
                size_t pos = extraData.find(':');
                if (pos != string::npos) {
                    string str = extraData.substr(pos + 1);
                    int capacity = stoi(str);
                    cout << "ID: " << id << ", Battery Capacity: " << capacity << endl;
                }
            } else if (type == "HybridTruck") {
                int cargoValue, batteryValue;
                size_t pos1 = extraData.find("Cargo:");
                size_t pos2 = extraData.find('|');

                if (pos1 != string::npos && pos2 != string::npos) {
                    string cargoString = extraData.substr(pos1 + 6, pos2 - (pos1 + 6));
                    cargoValue = stoi(cargoString);

                    size_t pos3 = extraData.find("Battery:");
                    if (pos3 != string::npos) {
                        string batteryString = extraData.substr(pos3 + 8);
                        batteryValue = stoi(batteryString);
                    }
                    cout << "ID: " << id << ", Cargo: " << cargoValue << ", Battery: " << batteryValue << endl;
                }
            } else {
                cout << "Error: Invalid Vehicle Type";
            }
        }
    }
}