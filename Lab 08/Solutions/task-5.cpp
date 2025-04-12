#include <iostream>
#include <string>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction(int n = 0, int d = 1) {
            if (d == 0) {
                cout << "Denominator set as 1 as it can't = zero." << endl;
                d = 1;
            }
            numerator = n;
            denominator = d;
        }

        Fraction operator+ (const Fraction& f) const {
            return Fraction(numerator * f.denominator + f.numerator * denominator,denominator * f.denominator);
        }

        Fraction operator- (const Fraction& f) const {
            return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
        }

        Fraction operator* (const Fraction& f) const {
            return Fraction(numerator * f.numerator, denominator * f.denominator);
        }

        Fraction operator/ (const Fraction& f) const {
            return Fraction(numerator * f.denominator, denominator * f.numerator);
        }

        friend ostream& operator<< (ostream& out, const Fraction& f);

};

ostream& operator<<(ostream& out, const Fraction& f) {
    int thisNum = 1;

    // Reducing to Lowest Term
    for (int i = 1; i <= f.denominator; i++) {
        if (f.numerator % i == 0 && f.denominator % i == 0) {
            thisNum = i;
        }
    }

    out << f.numerator / thisNum << "/" << f.denominator / thisNum;
    return out;
}

int main() {
    Fraction f1(4, 8), f2(2, 10);

    cout << "f1: 4/8, f2: 2/10\n\n";
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;
    return 0;
}