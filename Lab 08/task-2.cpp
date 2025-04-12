#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        float price;

    public:
        Book(string t, float p) : title(t), price(p) {}
        
        friend class Librarian;
};

class Librarian {
    public:
        void displayDetails(Book *b) {
            cout << "\nTitle: " << b->title << " --- Price: Rs " << b->price << endl; 
        }

        void applyDiscount(Book *b, float p) {
            if(p > 0 && p <= 100) {
                cout << "Discount applied on book: " << b->title << endl;
                b->price = b->price * (100 - p) / 100;
            } else {
                cout << "Discount must be (0-100) %" << endl; 
            }
        }
};

int main() {
    Book *b = new Book("Behave well", 50.8);
    Librarian ali;
    ali.displayDetails(b);
    ali.applyDiscount(b, 25);
    ali.displayDetails(b);

    delete b;
    return 0;
}