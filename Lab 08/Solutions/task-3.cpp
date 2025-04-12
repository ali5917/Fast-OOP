#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        char grades[3];

    public:
        Student(string n, char grade1, char grade2, char grade3) : name(n) {
            grades[0] = grade1;
            grades[1] = grade2;
            grades[2] = grade3;
        }

        friend float calculateAverageGrade(Student *s);
        friend class Teacher;
};

class Teacher {
    public:
        void viewGrade(Student *s) {
            cout << s->name << "'s grades:\n";
            for (int i = 0; i < 3; i++) {
                cout << "Subject " << i + 1 << ": " << s->grades[i] << endl;
            }
        }

        void updateGrade(Student *s, char grade1, char grade2, char grade3) {
            s->grades[0] = grade1;
            s->grades[1] = grade2;
            s->grades[2] = grade3;
            cout << "\n" << s->name << "'s grades updated" << endl;
        }

};

float calculateAverageGrade(Student *s) {
    float total = 0.0;
    for (int i = 0; i < 3; i++) {
        if (s->grades[i] == 'A') total += 4.0;
        else if (s->grades[i] == 'B') total += 3.0;
        else if (s->grades[i] == 'C') total += 2.0;
        else if (s->grades[i] == 'D') total += 1.0;
        else if (s->grades[i] == 'F') total += 0.0;
        else {
            cout << "Invalid grade\n";
        }
    }
    return total / 3.0;
}

int main() {
    Student *s1 = new Student("Ahmed Faraz", 'B', 'D', 'F');
    Teacher t;

    t.viewGrade(s1);
    cout << "Average grade: " << calculateAverageGrade(s1) << endl;

    t.updateGrade(s1, 'A', 'A', 'B');
    t.viewGrade(s1);
    cout << "Updated average grade: " << calculateAverageGrade(s1);

    delete s1;
    return 0;
}