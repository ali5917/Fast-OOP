#include <iostream> 
#include <climits>
using namespace std;
int main () {
    // Dynamic Array Manipulation
    int size, sum = 0, max = INT_MIN, thisValue;
    float avg;
    cout << "\nEnter the size of an Array: ";
    cin >> size;

    int *arrayPtr = new int[size];

    cout << "\nPopulating Array...\n";
    for (int i = 0; i < size; i++) {
        cout << "   Element " << i + 1 << ": ";
        cin >> thisValue;
        arrayPtr[i] = thisValue;
        sum += thisValue;
        if (thisValue > max) {
            max = thisValue;
        }
    }
    avg = (float) sum / size;
    cout << "\nSum: " << sum;
    cout << "\nAverage: " << avg;
    cout << "\nMaximum Value: " << max;

    delete[] arrayPtr;

    return 0;
}