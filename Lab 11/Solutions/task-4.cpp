#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class NegativeNumberException: public exception {
    public: 
        const char* what () const noexcept override {
            return "NegativeNumberException - Input must be non-negative!";
        }
};

class InvalidTypeException: public exception {
    public: 
        const char* what () const noexcept override {
            return "InvalidTypeException - Non Numeric Type detected!";
        }
};

template <typename T>
double computeSqrRoot(T num) {
    if(num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
    
}

double computeSqrRoot(const char* num) {
    throw InvalidTypeException();
}

double computeSqrRoot(string num) {
    throw InvalidTypeException();
}

int main () {
    try {
        cout << "sqrt(16): " << computeSqrRoot(16) << endl;
    } 
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(-4): " << computeSqrRoot(-4) << endl;
    } 
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): " << computeSqrRoot(string("hello")) << endl;
    } 
    catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << e.what() << endl;
    }
}