#include<iostream>
#include<string>
using namespace std;

class Professor {
    private:
        string name;
        string department;
    public:
        Professor(string n, string d) : name(n), department(d) {}
        string getName() {
            return name;
        }
        string getDepartment() {
            return department;
        }
};

class University {
    private:
        string name;
        string address;
        string* departments;
        Professor **professors;
        int numDepartments;
        int numProfessors;
    public:
        University(string n, string a) : name(n), address(a) {
            numProfessors = 0;
            professors = nullptr;

            cout << "Enter number of departments for university " << n << ": ";
            cin >> numDepartments;
            cin.ignore();
            departments = new string[numDepartments];
            for(int i = 0; i < numDepartments; i++) {
                cout << "Enter department " << i + 1 << ": ";
                getline(cin, departments[i]);
            }
        }
        void displayProfessors() {
            if (numProfessors == 0) {
                cout << "No professors in university " << name << endl;
                return;
            }
            cout  << endl << name << ": " << endl;
            for (int i = 0; i < numProfessors; i++) {
                cout << "Name: " << professors[i]->getName() << endl << "Department: " << professors[i]->getDepartment() << endl;
            }
            cout << endl;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        void addProfessor(Professor * newProfessor) {
            string department = newProfessor->getDepartment();
            bool found = false;
            for(int i = 0; i < numDepartments; i++) {
                if (department == departments[i]) {
                    found = true;
                }
            }
            if(!found) {
                cout << "No such Department in univeristy " << name << ", Could not add!" << endl;
                return;
            }
            Professor** temp = new Professor*[numProfessors + 1];
            for (int i = 0; i < numProfessors; i++){
                temp[i] =  professors[i];
            }
            delete[] professors;
            temp[numProfessors] = newProfessor;
            professors = temp;
            numProfessors++;
        }
        ~University() {
            delete[] professors;
            delete[] departments;
        }
};

int main() {
    University fast("FAST", "National Highway, Karachi");
    University ned("NED", "Service Road, Karachi");
    
    Professor* ali = new Professor("Ali Kashif", "CS");
    Professor* ismail = new Professor("Ismail Silat", "CS");
    Professor* hammad = new Professor("Hammad Rahim", "AI");
    Professor* sultan = new Professor("Sultan Ahmed", "SE");
    Professor* alih = new Professor("Ali Hussain", "SE");
    Professor* huzaifa = new Professor("Huzaifa Shahid", "AI");
    
    fast.addProfessor(ali);
    fast.addProfessor(ismail);
    fast.addProfessor(hammad);
    ned.addProfessor(sultan);
    ned.addProfessor(alih);
    ned.addProfessor(huzaifa);
    
    cout << "Professors List" << endl;
    fast.displayProfessors();
    ned.displayProfessors();
    
    delete ali;
    delete ismail;
    delete hammad;
    delete sultan;
    delete alih;
    delete huzaifa;
    return 0;
}