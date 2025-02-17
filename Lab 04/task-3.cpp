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
    	
        Book (string t, float p, int s) {
            title = t;
            price = p;
            stock = new int (s);
        }

//		copy constructor
		Book (Book &obj) {
			title = obj.title;
			price = obj.price;
			stock = new int (*obj.stock);
		}	
        
        ~Book () {
			delete stock;
			cout << "\nBook object: " << title << " destroyed.\n";
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
                cout << "\nNot enough stock! Only " << *stock << " copies remaining!\n"; 
                return;
            }
            
            applyDiscount(quantity);
        	*stock -= quantity;

    	    cout << "\nPurchase successful! " << quantity << " copies bought.\n";
	        cout << "Updated Price per book: $" << price << "\n";
            
			if (*stock < 5) {
                cout << "\nWarning: Low Stock! Only "  << *stock << " copies remaining!\n";
			}         
        }
        
        void applyDiscount (int quantity) {
        	int percent = 0;
			if (quantity > 10) {
        		price *= 0.90;
			} else if (quantity > 5 && quantity < 10) {
				price *= 0.95;
			}
		}
		
		void displayBook() {
	        cout << "\nTitle: " << title << "\nPrice: $" << price << "\nStock: " << *stock << "\n";
    	}
};

int main () {
	
    Book original("Goblin", 50.0, 12);
    original.displayBook();

    Book copy (original);
    cout << "\nCopy created.\n";
    copy.displayBook();

    original.updateBookDetails();
    cout << "\nAfter modifying the original:\n";
    original.displayBook();

    cout << "\nVerifying:\n";
    copy.displayBook();
    
    return 0;
}