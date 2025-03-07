#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;

        Person (string n, int a) : name (n), age (a) {}

        virtual void displayDetails () {
            cout << "Person Details:\n";
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
        }
};

class Teacher : virtual public Person {
    public:
        string subject;

        Teacher (string n, int a, string s) : Person (n, a), subject (s) {}

        void displayDetails () override {
            cout << "Teacher Details:\n";
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
            cout << "\nSubject: " << subject << endl;
        }
};  

class Researcher : virtual public Person {
    public: 
        string researchArea;

        Researcher (string n, int a, string r) : Person (n, a), researchArea(r) {}

        void displayDetails () override {
            cout << "Researcher Details:\n";
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
            cout << "\nResearch Area: " << researchArea << endl;
        }
};

class Professor : public Teacher, public Researcher {
    public:
        int publications;

        Professor (string n, int a, string s, string r, int p) : Person (n, a), Teacher (n, a, s), Researcher(n, a, r), publications (p) {}

        void displayDetails () override {
            cout << "Professor Details:\n";
            cout << "\nName: " << name;
            cout << "\nAge: " << age;
            cout << "\nSubject " << subject;
            cout << "\nResearch Area: " << researchArea;
            cout << "\nPublications " << publications << endl;
        }
};

int main () {
    Professor p1 ("Ahmed Raza", 30, "Computer Science", "AI", 10);
    p1.displayDetails();

    return 0;
}