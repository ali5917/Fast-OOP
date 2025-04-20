#include "Book.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;

    Book* book1 = new Book("How to C", "Ali", "122116");
    Book* book2 = new Book("Live Free", "Ruby", "932121");
    Book* book3 = new Book("Mind Games", "Shakin", "698613");

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.displayAllBooks();

    lib.removeBook("Mind Games");
    lib.displayAllBooks();
}