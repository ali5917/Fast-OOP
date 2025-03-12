#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    string rollNumber;
    float marks;
};

int main () {
    // Dynamic Memory Allocation for Records
    int numStudents, bestStudent = -1;
    float highestMarks = 0.0;
    cout << "\nEnter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    Student *students = new Student[numStudents];
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "   Name: ";
        getline(cin, students[i].name);
        cout << "   Roll Number: ";
        getline(cin, students[i].rollNumber);
        cout << "   Marks: ";
        cin >> students[i].marks;
        cin.ignore();
        
        if (students[i].marks > highestMarks) {
            highestMarks = students[i].marks;
            bestStudent = i;
        }
    }

    cout << "\nStudent with Highest Marks is:\n";
    cout << "\n   Name: " << students[bestStudent].name;
    cout << "\n   Roll Number: " << students[bestStudent].rollNumber;
    cout << "\n   Marks: " << fixed << setprecision(2) << students[bestStudent].marks << endl;

    delete[] students;
    return 0;
}