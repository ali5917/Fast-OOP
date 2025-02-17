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
	    
	    Book(string t, float p, int s) {
	        this->title = t;
	        this->price = p;
	        this->stock = new int(s);
	    }
	
	//	copy constructor
	    Book(Book &obj) {
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
	        cout << "\nTitle: " << this->title 
	             << "\nBase Price: $" << this->price 
	             << "\nStock: " << *this->stock << "\n";
	    }
};

int main() {
    Book book1("New World", 50.0, 15);

    book1.displayBook();

    book1.purchaseBook(6);
    book1.displayBook();

    book1.purchaseBook(10);
    Book book2 = book1;
    cout << "\nCopied book details:\n";
    book2.displayBook();

    return 0;
}
