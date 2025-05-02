#include <iostream>
#include <fstream>
using namespace std;


int main () {
    ifstream inFile;
    inFile.open("large_log.txt", ios::binary);
    if (!inFile.is_open()) {
        cout << "Failed to open file!" << endl;
        exit(1);
    }

    char chars10 [10];
    streampos pos;
    while(inFile.read(chars10, 10)) {
        pos = inFile.tellg();
        cout << "Position: " << pos << endl;
    }
    
    inFile.close();
}