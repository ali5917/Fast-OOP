#include <iostream>
#include <string>
using namespace std;

class TeaMug {
    private:
        string brand;
        string color;
        int currentFillLevel;
        int capacity;
    
    public:
        TeaMug(string b, string c, int l, int cap) : brand(b), color(c),  currentFillLevel(l), capacity(cap) {}
        
        void sip() {
            if (currentFillLevel > 0) {
                cout << "\nFatima is drinking Tea in a " << color << " " << brand << " Mug\n";
                currentFillLevel--;
            } else {
                cout << endl << color << " " << brand << " Mug is Empty. Time for a Fresh Cup!\n";
            }
        }

        void refill () {
            cout << endl << color << " " << brand << " Mug is being Refilled\n";
            currentFillLevel = capacity;
        }

        void checkEmpty () {
            if (currentFillLevel <= 0) {
                cout << endl << color << " " << brand << " Mug is empty. Time for a Fresh Cup!\n";
            } else {
                cout << endl << color << " " << brand << " Mug has tea remaining!\n";
            }
        }

        void displayStatus() {
            cout << endl << brand << " Mug (" << color << ") - Current Fill Level: " 
                 << currentFillLevel << " / " << capacity << endl;
        }
};

int main () {
    TeaMug myMug("Epson", "Blue", 3, 5);

    myMug.displayStatus();
    myMug.sip();
    myMug.sip();
    myMug.sip();
    myMug.sip();
    
    myMug.checkEmpty();

    myMug.refill();
    myMug.displayStatus();

    return 0;
}