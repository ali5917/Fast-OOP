#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        float price;
        int *stock;

    public:
        Book () {
            title = "Unknown";
            price = 0.0;
            stock = new int (30);
        }

		~Book () {
			delete stock;
		}

        void updateBookDetails () {
            cout << "\nEnter title: ";
            getline(cin, title);
            cout << "\nEnter price: ";
            cin >> price;
            cout << "\nEnter updated stock: ";
            cin >> *stock;
        }

        void purchaseBook (int quantity) {
            if (quantity > *stock) {
                cout << "\nNot enough stock!\n"; 
                return;
            }
            
			(*stock) -= quantity;
            
            cout << "\nPurchase successful! " << quantity << " copies bought.\n";
	        cout << "Price per book: $" << price << "\n";
            
			if (*stock < 5) {
                cout << "\nWarning: Low Stock!\n";
			}         
        }
        
        void displayBook() {
	        cout << "\nTitle: " << title << "\nPrice: $" << price << "\nStock: " << *stock << "\n";
    	}
};

int main () {
	Book thisBook;

    thisBook.updateBookDetails();
    thisBook.displayBook();

    thisBook.purchaseBook(6);
    thisBook.displayBook();

    thisBook.purchaseBook(4);
    
    return 0;
}
