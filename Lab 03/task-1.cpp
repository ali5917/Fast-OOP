#include <iostream>
#include <string>
using namespace std;

#define MAX_INK 10

class MarkerPen {
    private:
        string brand;
        string color;
        int inkLevel;
        bool refillability;
    
    public:
        MarkerPen(string b, string c, int i, bool r) : brand(b), color(c), inkLevel(i), refillability(r) {}
        
        void write() {
            if (inkLevel > 0) {
                cout << brand << " MarkerPen (" << color << ") is Writing\n";
                inkLevel--;
            } else {
                cout << brand << " MarkerPen (" << color << ") Needs Refilling!\n";
            }
        }

        void refill () {
            if (refillability) {
                cout << brand << " MarkerPen is being Refilled\n";
                inkLevel = MAX_INK; 
            } else {
                cout << brand << " MarkerPen is not Refillable\n";
            }
        }

        void displayStatus() {
            cout << "\nMarkerPen [" << brand << ", " << color << "] - Ink Level: " << inkLevel 
                 << " | Refillable: " << (refillability ? "Yes" : "No") << "\n\n";
        }
};

int main () {
    MarkerPen marker1("Dollar", "Blue", 5, true);
    MarkerPen marker2("Piano", "Black", 3, false);

    marker1.displayStatus();
    marker1.write();
    marker1.refill();
    marker1.displayStatus();

    marker2.displayStatus();
    marker2.write();
    marker2.refill();
    marker2.displayStatus();

    return 0;
}