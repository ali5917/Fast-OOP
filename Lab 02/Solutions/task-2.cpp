#include <iostream> 
#include <iomanip>
using namespace std;

int** makeMatrix (int rows, int cols) {
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

    return matrix;
}

void decorateMatrices (int **matrix1, int **matrix2, int rows, int cols, char op) {
    int done = 0;
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << left << setw(4) << matrix1[i][j];
        }
        if (!done) {
            cout << "          " << op << "          ";
            done = 1;
        } else {
            cout << "                     ";
        }
        for (int j = 0; j < cols; j++) {
            cout << left << setw(4) << matrix2[i][j];
        }
        cout << "\n";
    }

    cout << "\n";
}

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

void freeMatrix (int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void add (int **matrix1, int **matrix2, int rows, int cols) {
    decorateMatrices(matrix1, matrix2, rows, cols, '+');
    int **temp = new int*[rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int [cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << "Resultant Matrix\n";
    displayMatrix(temp, rows, cols);
    freeMatrix(temp, rows);
}

void subtract (int **matrix1, int **matrix2, int rows, int cols) {
    decorateMatrices(matrix1, matrix2, rows, cols, '+');
    int **temp = new int*[rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int [cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    cout << "Resultant Matrix\n";
    displayMatrix(temp, rows, cols);
    freeMatrix(temp, rows);
}

void multiply (int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    int **temp = new int*[rows1];
    for (int i = 0; i < rows1; i++) {
        temp[i] = new int [cols2] ();
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                temp[i][j] += (matrix1[i][k]) * (matrix2[k][j]);
            }
        }
    }
    cout << "\nResultant Matrix\n";
    displayMatrix(temp, rows1, cols2);
    freeMatrix(temp, rows1);
}

int main () {
    // 2D Matrix Operations
    int rows1, cols1, rows2, cols2;
    while (true) {
        int choice = 0;
        int **matrix1, **matrix2;

        cout << "\nChoose your Operation:";
        cout << "\n   1. Add";
        cout << "\n   2. Subtract";
        cout << "\n   3. Multiply";
        cout << "\n   4. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 4) {
            cout << "\nExiting...\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "\nEnter the number of Rows in Matrices Addition: ";
                cin >> rows1;
                cout << "Enter the number of Columns in Matrices Addition: ";
                cin >> cols1;
                cout << "\nMatrix 1";
                matrix1 = makeMatrix(rows1, cols1);
                cout << "\nMatrix 2";
                matrix2 = makeMatrix(rows1, cols1);
                add(matrix1, matrix2, rows1, cols1);
                
                freeMatrix(matrix1, rows1);
                freeMatrix(matrix2, rows1);
                break;
            case 2:
                cout << "\nEnter the number of Rows in Matrices Subtraction: ";
                cin >> rows1;
                cout << "Enter the number of Columns in Matrices Subtraction: ";
                cin >> cols1;
                cout << "\nMatrix 1";
                matrix1 = makeMatrix(rows1, cols1);
                cout << "\nMatrix 2";
                matrix2 = makeMatrix(rows1, cols1);
                subtract(matrix1, matrix2, rows1, cols1);
                
                freeMatrix(matrix1, rows1);
                freeMatrix(matrix2, rows1);
                break; 
            case 3:
                cout << "\nEnter the number of Rows in Matrix 1: ";
                cin >> rows1;
                cout << "Enter the number of Columns in Matrix 1: ";
                cin >> cols1;
                cout << "\nMatrix 1";
                matrix1 = makeMatrix(rows1, cols1);
                
                while (true) {    
                    cout << "\nEnter the number of Rows in Matrix 2: ";
                    cin >> rows2;
                    if (cols1 == rows2) {
                        break;  
                    } else {
                        cout <<"\nRows of 2nd Matrix must be Equal to Columns of First Matrix! (" << cols1 << ")\n";
                    }
                }
                cout << "Enter the number of Columns in Matrix 2: ";
                cin >> cols2;
                cout << "\nMatrix 2";
                matrix2 = makeMatrix(rows2, cols2);

                multiply(matrix1, matrix2, rows1, cols1, rows2, cols2);

                freeMatrix(matrix1, rows1);
                freeMatrix(matrix2, rows2);
                break;
            default:
                cout << "\nInvalid Choice!.\n"; 
                break;
        }
    }
}