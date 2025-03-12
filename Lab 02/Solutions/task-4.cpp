#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    string rollNumber;
    float marks[5];
};

void displayResults (Student *students, float *averages, int numStudents) {
    char grade;

    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << ": ";
        cout << "\n   Name: " << students[i].name << "      Roll Number: " << students[i].rollNumber;
        if (averages[i] >= 90) {
            grade = 'A';
        } else if (averages[i] >= 80 && averages[i] < 90) {
            grade = 'B';
        } else if (averages[i] >= 70 && averages[i] < 80) {
            grade = 'C';
        } else if (averages[i] >= 60 && averages[i] < 70) {
            grade = 'D';
        } else if (averages[i] >= 50 && averages[i] < 60) {
            grade = 'E';
        } else {
            grade = 'F';
        }
        cout << "\n   Marks:" ;
        for (int j = 0; j < 5; j++) {
            cout << " " << students[i].marks[j];
            if (j != 4) {
                cout << ",";
            }
        }
        cout << "\n   Average: " << fixed << setprecision(2) << averages[i] << "      Grade: " << grade << endl;
    }
}

int main () {
    // Student Grade Calculator
    int numStudents;
    float sum;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];
    float *averages = new float[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "   Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "   Roll Number: ";
        getline(cin, students[i].rollNumber);
        cout << "   Enter Marks in 5 Courses: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }
    }

    for (int i = 0; i < numStudents; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].marks[j];
        }
        averages[i] = sum / 5.0;
    }

    displayResults(students, averages, numStudents);

    delete[] students;
    delete[] averages;

    return 0;
}