#include <iostream>
#include <string>
using namespace std;

int getMonth() {
    cout << "\nChoose a Month:\n";
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int choice;
    for (int i = 0; i < 12; i++) {
        cout << "   " << i + 1 << ". " << months[i] << endl;
    }
    cout << "\nEnter Month (1-12): ";
    cin >> choice;
    return (choice - 1);
}

int getDay(int month) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int choice;
    cout << "Enter Day (1-" << days[month] << "): ";
    cin >> choice;
    return (choice - 1);
}

class Planner {
    private:
        string tasks[12][31];
    public:
        Planner () {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 31; j++) {
                    tasks[i][j] = "";
                }
            }
        }

        void add() {    
            int month = getMonth();
            int day = getDay(month);
            cout << "\nTask Name: ";
            cin.ignore();
            getline(cin, tasks[month][day]);

            cout << "\nTask Added Successfully!\n";
        }

        void remove() {    
            int month = getMonth();
            int day = getDay(month);
            if (tasks[month][day].empty()) {
                cout << "\nNo Task to Remove!\n";
            } else{
                tasks[month][day] = "";
                cout << "\nTask Removed Successfully!\n";
            }
        }

        void displayTasks() {
            int flag;
            bool fill = false;
            string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
            for (int i = 0; i < 12; i++) {
                flag = 0;
                for (int j = 0; j < days[i]; j++) {
                    if (tasks[i][j] != "") {
                        if (!flag) {
                                cout << endl << months[i] << ":\n";
                                flag = 1;
                        }
                        cout << "   " << j + 1 << ". " << tasks[i][j] << endl;
                        fill = true;
                    }
                }
            }
            if (!fill) {
                cout << "\nNo scheduled Tasks\n";
            }
        }
};

int main () {
    Planner myPlanner;
    int choice;
    
    while (true) {
        cout << "\n1. Add Task";
        cout << "\n2. Remove Task";
        cout << "\n3. Display Tasks";
        cout << "\n4. Exit";
        cout << "\nEnter your Choice (1-4): ";
        cin >> choice;

        if (choice == 4) {
            cout << "\nExiting\n";
            break;
        }

        switch (choice) {
            case 1:
                myPlanner.add(); 
                break;
            case 2:
                myPlanner.remove(); 
                break;
            case 3:
                myPlanner.displayTasks(); 
                break;
            default:
                cout << "\nPlease Enter a Valid Choice!\n";
        }
    }
    return 0;
}