#include <iostream>
#include <fstream>
#include <string>
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
            cout << thisLine << endl;
        }
    }
}