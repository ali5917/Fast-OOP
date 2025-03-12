#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

void swap (int *arr, int numElements, int index1, int index2) {
    int temp;

    if (index1 >= 0 && index1 < numElements && index2 >= 0 && index2 < numElements) {
        temp = *(arr + index1);
        *(arr + index1) = *(arr + index2);
        *(arr + index2) = temp;
    } else {
        cout << "\nInvalid Index!";
        return;
    }
}

void reverse (int *arr, int numElements) {
    int *start = arr;
    int *end = arr + numElements - 1;

    while (start < end) {
        swap(arr, numElements, start - arr, end - arr);
        start++;
        end --;
    }    
}

int main () {
    // Pointers and Functions
    int numElements, index1, index2;
    cout << "\nEnter the number of Elements in Array: ";
    cin >> numElements;

    int *arr = new int[numElements];
    cout << "\nPopulating Array:\n";
    for (int i = 0; i < numElements; i++) {
        cout << "   Element " << i + 1 << ": ";
        cin >> arr[i];
    } 

    while (true) {
        int choice = 0;

        cout << "\nArray:";
        for (int i = 0; i < numElements; i++) {
            cout << " " << arr[i];
        }
        
        cout << "\n\nChoose your Operation:";
        cout << "\n   1. Swap";
        cout << "\n   2. Reverse";
        cout << "\n   3. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 3) {
            cout << "\nExiting...\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "\nEnter 2 indexes to be swapped: ";
                cin >> index1;
                cin >> index2;
                swap(arr, numElements, index1, index2);
                break;
            case 2:
                reverse(arr, numElements);
                break; 
            default:
                cout << "Please Enter a valid Choice!\n"; 
                break;
        }
    }

    delete[] arr;
    return 0;
}