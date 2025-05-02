#include <iostream>
#include <fstream>
using namespace std;


int main () {
    ifstream inFile;
    inFile.open("data_records.txt", ios::binary);
    if (!inFile.is_open()) {
        cout << "Failed to open file!" << endl;
        exit(1);
    }

    char chars[10];
    inFile.seekg(2 * 10, ios::beg);
    inFile.read(chars, 10);
    chars[9] = '\0';
    cout << "Extracted line: " << chars << endl;

    inFile.close();

}