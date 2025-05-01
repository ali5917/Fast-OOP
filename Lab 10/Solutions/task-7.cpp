#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
    ofstream outFile;
    outFile.open("sensor_log.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file!";
        exit(1);
    }

    outFile << "Sensor 3: 20.3 C\n";
    streampos pos1 = outFile.tellp();
    cout << "Position after 1st appended Line: " << pos1 << endl; 

    outFile << "Sensor 4: 96.2 %RH\n";
    streampos pos2 = outFile.tellp();
    cout << "Position after 2nd appended Line: " << pos2 << endl;
    
    outFile.close();
}