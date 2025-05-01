#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class InventoryItem {
    public:
        int itemID;
        char itemName[50];

        InventoryItem () {};
        InventoryItem(int i, string n) : itemID(i) {
            strcpy(itemName, n.c_str());
        }
};

int main () {
    InventoryItem item1 (102, "Pencil Box");
    ofstream outFile;
    outFile.open("inventory.dat", ios::binary);
    if (!outFile.is_open()) {
        cout << "Error opening output file!";
        exit(1);
    }

    outFile.write((char *)&item1, sizeof(item1));
    outFile.close();

    InventoryItem item2;    
    ifstream inFile;
    inFile.open("inventory.dat", ios::binary);
    if (!inFile.is_open()) {
        cout << "Error opening input file!";
        exit (1);
    }

    inFile.read((char *)&item2, sizeof(item2));
    inFile.close();

    cout << "\nNew Item\nID: " << item2.itemID << ", Name: " << item2.itemName << endl;
}