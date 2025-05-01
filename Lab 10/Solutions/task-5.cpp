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
            } 


        }
    }
}