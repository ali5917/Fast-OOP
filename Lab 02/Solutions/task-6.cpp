#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    int isAvailable;
};

void add(Book *&books, int *numBooks) {
    Book *temp = new Book[*numBooks + 1];
    for (int i = 0; i < *numBooks; i++) {
        temp[i] = books[i];
    }
    cout << "\nEnter Book Details:\n";
    cout << "   ID: ";
    cin >> temp[*numBooks].bookID;
    cin.ignore();
    cout << "   Title: ";
    getline(cin, temp[*numBooks].title);
    cout << "   Author: ";
    getline(cin, temp[*numBooks].author);
    cout << "   Is Book Available (1 if Yes / 0 if No): ";
    cin >> temp[*numBooks].isAvailable;

    delete[] books;
    books = temp;
    (*numBooks) += 1;

    cout << "\nBook Added Successfully!\n";
}

void remove(Book *&books, int *numBooks) {
    int thisID, found = 0, index;

    cout << "\nEnter Book ID to be Removed:";
    cin >> thisID;
    for (int i = 0; i < *numBooks; i++) {
        if (books[i].bookID == thisID) {
            found = 1;
            index = i;
            break;
        }
    }
    if (!found) {
        cout << "\nNo Book with Matching ID!\n";
        return;
    }

    Book *temp = new Book[*numBooks - 1];
    int j = 0;
    for (int i = 0; i < *numBooks; i++) {
        if (i != index) {
            temp[j++] = books[i];
        }
    }

    delete[] books;
    books = temp;
    (*numBooks) -= 1;

    cout << "\nBook Removed Successfully!\n";
}

void searchBook(Book *books, int numBooks) {
    int thisID, found = 0;

    cout << "\nEnter Book ID to Search: ";
    cin >> thisID;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookID == thisID) {
            found = 1;
            cout << "\nBook Details:\n";
            cout << "\n   ID: " << books[i].bookID;
            cout << "\n   Title: " << books[i].title;
            cout << "\n   Author: " << books[i].author;
            cout << "\n   Availability: " << (books[i].isAvailable ? "Yes": "No") << endl;
        }
    }
    if (!found) {
        cout << "\nNo Book with Matching ID!\n";
    }
}

void displayBooks(Book *books, int numBooks) {
    cout << "\nBooks List:\n";
    for (int i = 0; i < numBooks; i++) {
            cout << "\n   ID: " << books[i].bookID;
            cout << "\n   Title: " << books[i].title;
            cout << "\n   Author: " << books[i].author;
            cout << "\n   Availability: " << (books[i].isAvailable ? "Yes": "No") << endl;
    }
}

int main () {
    // Library Management System
    int numBooks = 0;
    Book *books = new Book[numBooks + 1];

    while (true) {
        int choice = 0;
        
        cout << "\nChoose your Operation:";
        cout << "\n   1. Add Book";
        cout << "\n   2. Remove Book";
        cout << "\n   3. Search Book";
        cout << "\n   4. Display Books";
        cout << "\n   5. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 5) {
            cout << "\nExiting...";
            break;
        }

        switch (choice) {
            case 1:
                add(books, &numBooks);
                break;
            case 2:
                remove(books, &numBooks);
                break; 
            case 3:
                searchBook(books, numBooks);
                break; 
            case 4:
                displayBooks(books, numBooks);
                break; 
            default:
                cout << "Please Enter a valid Choice!\n"; 
                break;
        }
    }
    
    delete[] books;
    return 0;
}