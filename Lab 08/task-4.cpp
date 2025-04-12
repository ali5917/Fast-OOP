#include <iostream>
#include <string>
using namespace std;

class Currency {
    private:
        float value;

    public:
        Currency(float m) : value(m) {}
        
        //Operator Overloading Functions
        Currency operator- () {
            return Currency(-value);
        }

        Currency operator+ (const Currency& c) {
            return Currency(value + c.value);
        }

        Currency operator- (const Currency& c) {
            return Currency(value - c.value);
        }

        Currency operator+= (const Currency& c) {
            value += c.value;
            return *this;
        }

        Currency operator-= (const Currency& c) {
            value -= c.value;
            return *this;
        }

        friend ostream& operator<< (ostream& out, const Currency& c);        
};

ostream& operator<< (ostream& out, const Currency& c) {
    out << "Value: " << c.value;
    return out;
}

int main() {
    Currency c1(100);
    Currency c2(50);

    Currency c3 = c1 + c2;
    Currency c4 = c3 - c2;
    Currency c5 = -c4;
    c1 += c3;
    c4 -= c5;

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    cout << c5 << endl;
    return 0;
}