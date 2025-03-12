#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

void displayMatrix (int **matrix, int rows, int cols) {
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << left << setw(4) << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void makeTranspose(int **matrix, int rows, int cols) {
    int **transposeMatrix = new int *[cols];
    for (int i = 0; i < cols; i++) {
        transposeMatrix[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(transposeMatrix + j) + i) = *(*(matrix + i) + j);
        }
    }

    displayMatrix (transposeMatrix, cols, rows);
    
    for (int i = 0; i < cols; i++) {
        delete[] transposeMatrix[i];
    }
    delete[] transposeMatrix;
}

int main () {
    // Matrix Transpose Using Pointers
    int rows, cols;
    cout << "\nEnter the number of Rows: ";
    cin >> rows;
    cout << "Enter the number of Columns: ";
    cin >> cols;

    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "\nPopulating the Matrix...\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "   Row " << i << ", Column " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix\n";
    displayMatrix(matrix, rows, cols);
    cout << "Transpose of Matrix\n";
    makeTranspose(matrix, rows, cols);


    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}