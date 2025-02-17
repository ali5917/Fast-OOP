#include <iostream>
#include <string>
using namespace std;

class Book {
	private:
	    string title;
	    float price;
	    int *stock;
	    int bookID;
	    static int bookCounter;
	
	public:
		Book () {
	            title = "Unknown";
	            price = 0.0;
	            stock = new int (30);
	    }
	        
	    Book(string t, float p, int s) : bookID(bookCounter++){
	        this->title = t;
	        this->price = p;
	        this->stock = new int(s);
	    }	    
	
	//	copy constructor
	    Book(Book &obj) : bookID(bookCounter++) {
	        this->title = obj.title;
	        this->price = obj.price;
	        this->stock = new int(*obj.stock);
	    }
	
	    ~Book() {
	        delete stock;
	        cout << "\nBook object: " << this->title << " destroyed.\n";
	    }
	
	    void updateBookDetails() {
	        cout << "\nEnter title: ";
	        getline(cin, this->title);
	        cout << "\nEnter price: ";
	        cin >> this->price;
	        cout << "\nEnter updated stock: ";
	        cin >> *(this->stock);
	    }
	
	    float newPrice(int quantity) {
	        float finalPrice = this->price;
	        
	        if (quantity > 10) {
	            finalPrice *= 0.90;
	        } else if (quantity > 5) {
	            finalPrice *= 0.95; 
	        }
	
	        return finalPrice;
	    }
	
	    void purchaseBook(int quantity) {
	        if (quantity > *this->stock) {
	            cout << "\nNot enough stock! Only " << *this->stock << " copies remaining!\n";
	            return;
	        }
	
	        float discountedPrice = newPrice(quantity);
	        *this->stock -= quantity;
	
	        cout << "\nPurchase successful! " << quantity << " copies bought.\n";
	        cout << "Final Price per book after discount: $" << discountedPrice << "\n";
	
	        if (*this->stock < 5) {
	            cout << "\nWarning: Low Stock! Only " << *this->stock << " copies remaining!\n";
	        }
	    }
	
	    void displayBook() {
	        cout << "\nBook ID: " << bookID << "\nTitle: " << this->title << "\nBase Price: $" << this->price << "\nStock: " << *this->stock << "\n";
	    }
};

int Book::bookCounter = 1;

int main() {
    Book book1("Clean Soul", 39.99, 10);
    Book book2("Heart of Gold", 49.99, 5);
    Book book3 = book1;

    book1.displayBook();
    book2.displayBook();
    book3.displayBook();

    return 0;
}
