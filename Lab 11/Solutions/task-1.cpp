#include <iostream>
#include <string>
using namespace std;

class InvalidValueException: public exception {

    public:
        const char* what () const noexcept override {
            return "InvalidValueException - Age cannot be negative or exceeds 120";
        }
};

void validateAge(int age) {
    if (age < 0 || age > 120) {
        throw InvalidValueException();
    } else {
        cout << "Age is valid\n";
    }
}

int main () {
    int age;
    cout << "Enter age: ";
    cin >> age;

    try {
        validateAge(age);
    } catch (const InvalidValueException &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}