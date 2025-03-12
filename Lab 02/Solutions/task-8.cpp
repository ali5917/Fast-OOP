#include <iostream> 
#include <climits>
#include <iomanip>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    float price;
};

void add(Product *&products, int *numProducts) {
    Product *temp = new Product[*numProducts + 1];
    for (int i = 0; i < *numProducts; i++) {
        temp[i] = products[i];
    }
    cout << "\nEnter Product Details:\n";
    cout << "   ID: ";
    cin >> temp[*numProducts].productID;
    cin.ignore();
    cout << "   Title: ";
    getline(cin, temp[*numProducts].name);
    cout << "   Quantity: ";
    cin >> temp[*numProducts].quantity;
    cout << "   Price: ";
    cin >> temp[*numProducts].price;

    delete[] products;
    products = temp;
    (*numProducts) += 1;

    cout << "\nProduct Added Successfully!\n";
}

void remove(Product *&products, int *numProducts) {
    int thisID, found = 0, index;

    cout << "\nEnter Product ID to be Removed:";
    cin >> thisID;
    for (int i = 0; i < *numProducts; i++) {
        if (products[i].productID == thisID) {
            found = 1;
            index = i;
            break;
        }
    }
    if (!found) {
        cout << "\nNo Product with Matching ID!\n";
        return;
    }

    Product *temp = new Product[*numProducts - 1];
    int j = 0;
    for (int i = 0; i < *numProducts; i++) {
        if (i != index) {
            temp[j++] = products[i];
        }
    }

    delete[] products;
    products = temp;
    (*numProducts) -= 1;

    cout << "\nProduct Removed Successfully!\n";
}

void update(Product *products, int numProducts) {
    int thisID, found = 0;

    cout << "\nEnter Product ID to Update: ";
    cin >> thisID;

    for (int i = 0; i < numProducts; i++) {
        if (products[i].productID == thisID) {
            found = 1;
            cout << "\n   Enter New Quantity: ";
            cin >> products[i].quantity;
            cout << "\n   Enter New Price: ";
            cin >> products[i].price;
            cout << "\nProduct Updated\n";
            break;
        }
    }
    if (!found) {
        cout << "\nNo Product with Matching ID!\n";
    }
}

void displayProducts(Product *products, int numProducts) {
    cout << "\nProducts List:\n";
    for (int i = 0; i < numProducts; i++) {
            cout << "\n   ID: " << products[i].productID;
            cout << "\n   Name: " << products[i].name;
            cout << "\n   Quantity: " << products[i].quantity;
            cout << "\n   Price: " << products[i].price << endl;
    }
}

float calcTotal (Product *products, int numProducts) {
    float total = 0.0;
    for (int i = 0; i < numProducts; i++) {
        total += (products[i].price * products[i].quantity);
    }

    return total;
}

int main () {
    // Library Management System
    int numProducts = 0;
    Product *products = new Product[numProducts + 1];

    while (true) {
        int choice = 0;
        float total = calcTotal(products, numProducts);
        cout << "\nTotal Inventory: " << fixed << setprecision(2) << total << "\n";

        cout << "\nChoose your Operation:";
        cout << "\n   1. Add Product";
        cout << "\n   2. Remove Product";
        cout << "\n   3. Update Product";
        cout << "\n   4. Display Products";
        cout << "\n   5. Exit";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        
        if (choice == 5) {
            cout << "\nExiting...";
            break;
        }

        switch (choice) {
            case 1:
                add(products, &numProducts);
                break;
            case 2:
                remove(products, &numProducts);
                break; 
            case 3:
                update(products, numProducts);
                break; 
            case 4:
                displayProducts(products, numProducts);
                break; 
            default:
                cout << "Please Enter a valid Choice!\n"; 
                break;
        }
    }
    
    delete[] products;
    return 0;
}