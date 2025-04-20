#ifndef BOOK
#define BOOK
#include <iostream>
using namespace std;

class Book {
    private:
        string title;
        string author;
        string ISBN;

    public:
        Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
        
        string getTitle() { 
            return title; 
        }

        string getAuthor() { 
            return author; 
        }

        string getISBN() { 
            return ISBN; 
        }

        void displayBook() {
            cout << "\nTitle: " << title << endl << "Author: " << author << endl << "ISBN: " << ISBN << "\n\n";
        }

};

class Library {
    private:
        Book ** books;
        int numBooks;

    public:
        Library() : books(nullptr), numBooks(0) {}
        
        void addBook(Book * b) {
            Book** temp =  new Book * [numBooks + 1];
            
            for(int i = 0; i < numBooks; i++) {
                temp[i] =  books[i];
            }

            temp[numBooks] = b;
            delete[] books;
            books = temp;
            numBooks++;
            
            cout << "Book " << b->getTitle() << " has been added!\n";
        }
        
        int searchBook(string title) {
            for(int i = 0; i < numBooks; i++) {
                if (books[i]->getTitle() == title) {
                    cout << "Book: " << title << " found at index: " << i << endl;
                    return i;
                }
            }

            cout << "Book " << title << " not found" << endl;
            return -1;
        }

        void removeBook(string title) {
            int index = searchBook(title);
            if(index == -1) { 
                cout << "Invalid Index";
                return;
            }

            Book** tempBooks = new Book*[numBooks - 1];
           
            for(int i = 0; i < index; i++) {
                tempBooks[i] = books[i];
            }
           
            for(int i = index + 1; i < numBooks; i++) {
                tempBooks[i - 1] = books[i];
            }
           
            delete books[index];
            delete[] books;
            books = tempBooks;
            numBooks--;
            
            cout << "Book " << title << " removed\n";
        }

        void displayAllBooks() {
            for (int i = 0; i < numBooks; i++) {
                books[i]->displayBook();
            }
        }

        ~Library() {
            delete[] books;
        }

};

#endif