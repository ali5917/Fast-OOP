#include<iostream>
#include<string>
using namespace std;

class Product {
    private:
        static int uniqueID;
        int id;
        string name;
        float price;
    public:
        Product(string n, float p) :name(n), price(p), id(uniqueID++) {}

        int getID() { 
            return id; 
        }

        string getName() { 
            return name; 
        }
        
        float getPrice() { 
            return price; 
        }
};

class GroceryStore {
    private:
        int numProducts;
        Product** products;
    public:
        GroceryStore() {
            numProducts = 0;
            products = nullptr;
        }

        void addProduct(Product* product) {
            Product ** temp = new Product* [numProducts + 1];
            for(int i = 0; i < numProducts; i++) {
                temp[i] = products[i];
            }
            temp[numProducts] = product;
            delete[] products;
            products = temp;
            numProducts++;
            cout << "Added Product: " << product->getName() << endl;
        }

        void displayProducts() {
            if (numProducts == 0) {
                cout << "Empty Store" << endl;
                return;
            }

            for (int i = 0; i < numProducts; i++) {
                cout << "ID: " << products[i]->getID() << ", Name: " << products[i]->getName()  << ", Price: $" << products[i]->getPrice() << endl;
            }
            cout << endl;
        }    
        void removeProduct() {
            int ID;
            cout << "Product ID to be removed: ";
            cin >> ID;
            cin.ignore();
            int index = -1;
            for (int i = 0; i < numProducts; i++) {
                if (products[i]->getID() == ID) {
                    index = i;
                    break;
                }
            }
    
            if (index == -1) {
                cout << "Failed Removal. Product " << ID << " not found!" << endl;
                return;
            }

            Product** temp = new Product* [numProducts - 1];
            for (int i = 0; i < index; i++) {
                temp[i] = products[i];
            }
            for (int i = index; i < numProducts - 1; i++) {
                temp[i] = products[i + 1];
            }
            delete[] products;
            products = temp;
            numProducts--;
    
            cout << "Product " << ID << " removed!" << endl << endl;
        }
        void searchProduct() {
            string name;
            cout << "Name of Product: ";
            getline(cin, name);
            bool found = false;
            int index;
            for(int i = 0; i < numProducts; i++) {
                if(name == products[i]->getName()) {
                    found = true;
                    index = i;
                }
            }
            if(!found) {
                cout << "Product " << name << " not found!" << endl;
                return;
            }
            cout << "ID: " << products[index]->getID() << ", Name: " << products[index]->getName() << ", Price: $" << products[index]->getPrice() << endl;
        }
        void sortProducts() {
            for(int i = 0; i < numProducts - 1; i++) {
                for(int j = 0; j < numProducts - i - 1; j++) {
                    if(products[j]->getPrice() > products[j+1]->getPrice()) {
                        Product * temp = products[j];
                        products[j] = products[j + 1];
                        products[j + 1] = temp;
                    }
                }
            }
            cout << "Cheapest Product -> " << "ID: " << products[0]->getID() << ", Name: " << products[0]->getName() << ", Price: $" << products[0]->getPrice() << endl;
        }
        ~GroceryStore() {
            delete[] products;
        }
};

int Product::uniqueID = 0;

int main() {
    GroceryStore store;

    Product* AC = new Product("AC", 500.0);
    Product* sugar = new Product("Sugar", 2.0);
    Product* rice = new Product("Rice", 3.5);

    store.addProduct(AC);
    store.addProduct(sugar);
    store.addProduct(rice);
    store.displayProducts();
    store.removeProduct();
    store.searchProduct();
    store.sortProducts();
    store.displayProducts();

    delete AC;
    delete sugar;
    delete rice;
    return 0;
}