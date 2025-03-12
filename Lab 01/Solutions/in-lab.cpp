#include <iostream>
#include <string.h>
using namespace std;
int main () {

// Register Event Participants
    int max1, max2;

    cout << "\nEnter the Max number of participants in event 1: ";
    cin >> max1;
    cin.ignore();

    string event1[max1];

    for (int i = 0; i < max1; i++) {
        cout << "Please enter name " << i + 1 << " for event 1: ";
        getline(cin, event1[i]);
    }

    cout << "\nEnter the Max number of participants in event 2: ";
    cin >> max2;
    cin.ignore();
    
    string event2[max2];

    for (int i = 0; i < max2; i++) {
        cout << "Please enter name " << i + 1 << " for event 2: ";
        getline(cin, event2[i]);
    }

// Attendance Checker

    string thisName;
    int found = 0;

    cout << "\nEnter the name of participant to be searched: ";
    getline(cin, thisName);

    for (int i = 0; i < max1; i++) {
        if (event1[i] == thisName) {
            cout << thisName << " is registered in event 1.\n";
            found = 1;
        }
    }

    for (int i = 0; i < max2; i++) {
        if (event2[i] == thisName) {
            cout << thisName << " is registered in event 2.\n";
            found = 1;
        }
    }

    if (!found) {
        cout << "\n" << thisName << " is not registered in both events!\n";
    }

// Calculate Total Donations

    int totalDonations = (max1 * 10) + (max2 * 10);
    cout << "\nTotal Donations Collected is $" << totalDonations << "\n\n";

// Display Participant Names in Reverse

    cout << "\nEvent 1 in Reverse Order:" << endl;
    for (int i = max1 - 1; i >= 0; i--) {
        cout << event1[i] << endl;
    }

    cout << "\nEvent 2 in Reverse Order:" << endl;
    for (int i = max2 - 1; i >= 0; i--) {
        cout << event2[i] << endl;
    }

// Event Popularity Bar Chart

    cout << "\n\n";
    int highMax;
    if (max1 > max2) {
        highMax = max1;
    } else {
        highMax = max2;
    }

    for (int i = highMax; i > 0; i--) {
        if (max1 >= i) {
            cout << "  *    ";
        } else {
            cout << "       ";
        }

        if (max2 >= i) {
            cout << "     *";
        } else {
            cout << "      ";
        }

        cout << endl;
    }
    cout << "Event 1   Event 2\n";  
    
    return 0;
}