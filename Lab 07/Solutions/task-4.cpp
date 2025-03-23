#include <iostream>
#include<string>
using namespace std;

class Student;
class Professor;

class Course {
    private:
        int courseID;
        string name;
        int credits;
        Professor* instructor;
        string schedule;
    
    public:
        Course(int c, string n, int cr, Professor* i, string s) : courseID(c), name(n), credits(cr), instructor(i), schedule(s) {
            assignProfessor();
        }
        
        void registerStudent(Student * s);
        void assignProfessor();
        void displayDetails() {
            cout << "CourseID: " << courseID << endl << "CourseName: " << name << endl << "Credit Hours: " << credits << endl << "Schedule: " << schedule << endl;
        }
        
        string getName() { return name; }
};

class Person {
    protected:
        string name;
        int id;
        string address;
        string phoneNumber;
        string email;
        
    public:
        Person(string n, int i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
       
        virtual void displayInfo() {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "Address: " << address << endl << "Phone Number: " << phoneNumber << endl << "Email: " << email << endl;
        }
      
        void updateInfo(string a, string p, string e) {
            address = a;
            phoneNumber = p;
            email = e;
        }
};

class Student : public Person {
    private:
        Course** coursesEnrolled;
        float GPA;
        int enrollmentYear;
        int numCourses;

    public:
        Student(string n, int i, string a, string p, string e, float g, int y) : Person(n, i, a, p, e), GPA(g), enrollmentYear(y), numCourses(0), coursesEnrolled(nullptr) {}
        
        void displayInfo() override {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "GPA: " << GPA << endl << "Enrollment Year: " << enrollmentYear << endl << "Courses Enrolled:" << endl;
            
            for(int i = 0; i < numCourses; i++) {
                coursesEnrolled[i]->displayDetails();
                cout << endl;
            }
        }
        
        void enrollInCourse(Course *c ) {
            Course** tempEnrolled = new Course*[numCourses + 1];
            
            for(int i = 0; i < numCourses; i++) {
                tempEnrolled[i] = coursesEnrolled[i];
            }
            
            tempEnrolled[numCourses] = c;
            delete[] coursesEnrolled;
            coursesEnrolled = tempEnrolled;

            cout << name << " enrolled in course " << c->getName() << endl;
            numCourses++;
        }
};

void Course::registerStudent(Student * s) {
    s->enrollInCourse(this);
}

class Professor : public Person {
    private:
        string department;
        Course** coursesTaught;
        int numCourses;
        float salary;

    public:
        Professor(string n, int i, string a, string p, string e, string dept, float s) : Person(n, i, a, p, e), department(dept), salary(s), numCourses(0), coursesTaught(nullptr) {}
        
        void displayInfo() override {
            cout<< "ID: " << id << endl << "Name: " << name << endl << "Department: " << department << endl << "Salary: " << salary << endl << "Courses Taught: " << endl;
            for(int i = 0; i < numCourses; i++) {
                coursesTaught[i]->displayDetails();
                cout << endl;
            }
        }
        
        void assignCourse(Course* c) {
            Course** tempCourses = new Course * [numCourses + 1];
            
            for (int i = 0; i < numCourses; i++) {
                tempCourses[i] = coursesTaught[i];
            }
            
            tempCourses[numCourses] = c;
            delete[] coursesTaught;
            coursesTaught = tempCourses;
            
            cout << name << " assigned to course " << c->getName() << endl;
            numCourses++;
        }
};

void Course::assignProfessor() {
    instructor->assignCourse(this);
}

class Staff : public Person {
    private:
        string department;
        string position;
        float salary;
    public:
        Staff(string n, int i, string a, string p, string e, string dept, string pos, float s) : Person(n, i, a, p, e), department(dept), position(pos), salary(s) {}
        
        void displayInfo() override {
            cout << "ID: " << id << endl << "Name: " << name << endl << "Department: " << department << endl << "Salary: " << salary << endl << "Position: " << position << endl;
        }
};


int main() {
    Professor musa("Musa Kamil", 1, "North Karachi", "123-456-7890", "musa@nu.edu.pk", "AI", 150000);
    Professor arif("Arif Faisal", 2, "East Karachi", "987-654-3210", "arif@nu.edu.pk", "Biology", 140000);

    Staff ahmed("Ahmed Faraz", 1, "Gulshan", "0-900-786-01", "ahmed@nu.edu.pk", "Computer Science", "Head", 145000);

    Student ali("Ali Kashif", 1, "Lyari", "444-555-6666", "ali@nu.edu.pk", 3.5, 2024);
    Student ismail("Ismail Silat", 2, "PECHS", "111-222-3333", "ismail@nu.edu.pk", 3.8, 2024);

    Course math(1, "Math", 4, &musa, "Monday 10:00-11:30 AM");
    Course physics(2, "Physics", 3, &arif, "Tuesday 9:00-10:30 AM");

    ali.enrollInCourse(&math);
    ismail.enrollInCourse(&math);
    ali.enrollInCourse(&physics);

    cout << "\n--- Professor Details ---\n";
    musa.displayInfo();
    arif.displayInfo();

    cout << "\n--- Student Details ---\n";
    ali.displayInfo();
    ismail.displayInfo();

    return 0;
}