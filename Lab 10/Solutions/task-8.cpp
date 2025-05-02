#include <iostream>
#include <fstream>
using namespace std;

int main () {
    fstream file;
    if (file.is_open()) {
        cout << "Failed to open file!" << endl;
        exit(1);
    }

    file.open("config.txt", ios::in | ios::out);
    file.seekp(5, ios::beg);
    file << "XXXXX";
    file.close();
}