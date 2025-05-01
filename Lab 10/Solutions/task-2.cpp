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
        exit(1);
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

            cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << ", Extra Data: " << extraData << ", Certification: " << certification << endl;
        }
    }
}