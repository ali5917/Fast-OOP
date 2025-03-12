#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

void concat (string *str1, string *str2) {
    cout << "\nConcatenated String: " << *str1 + *str2;
}

void compare (string *str1, string *str2) {
    if (*str1 > *str2) {
        cout << "\n1";
    } else if (*str1 < *str2) {
        cout << "\n-1";
    } else {
        cout << "\n0";
    }
}

void findLength (string *str1, string *str2) {
    cout << "\nFirst String Length: " << str1->length();
    cout << "\nSecond String Length: " << str2->length();
}

int main () {
    // Dynamic String Manipulation
    string *str1 = new string;
    string *str2 = new string;

    while (true) {
        int choice = 0;
        
        cout << "\n\nChoose your Operation:";
        cout << "\n   1. Concatenate";
        cout << "\n   2. Compare";
        cout << "\n   3. Find Length";
        cout << "\n   4. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 4) {
            cout << "\nExiting...";
            break;
        } 

        cin.ignore();
        cout << "\nEnter First String: ";
        getline(cin, *str1);
        cout << "Enter Second String: ";
        getline(cin, *str2);

        switch (choice) {
            case 1:
                concat(str1, str2);
                break;
            case 2: 
                compare(str1, str2);
                break;
            case 3:
                findLength(str1, str2);
                break;
            default:
                cout << "\nInvalid Choice!\n";
                break;
        }
    }

    delete[] str1;
    delete[] str2;
    return 0;
}