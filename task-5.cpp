#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Item {
    string name;
    float price;
};

class GroceryStore {
    private:
        int capacity;
        int count;
        Item *items;
    public:
        GroceryStore() {
            cout << "\nEnter initial capacity for the store: ";
            cin >> capacity;
            count = 0;
            items = new Item[capacity];
        }

        ~GroceryStore() {
            delete[] items;
        }

        void add() {
            if (count >= capacity)  {
                capacity *= 2;
                Item *temp = new Item[capacity];
                for (int i = 0; i < count; i++) {
                    temp[i] = items[i];
                }
                delete[] items;
                items = temp;
            }

            cout << "\nItem Name: ";
            cin.ignore();
            getline(cin, items[count].name);
            cout << "\nItem Price: Rs ";
            cin >> items[count].price;
            count += 1;
            cout << "\nItem Added Successfully.\n";
        }

        void updatePrice () {
            string thisItem;
            float thisPrice;
            int found = 0;

            cout << "\nEnter Item Name: ";
            cin.ignore();
            getline(cin, thisItem);
            for (int i = 0; i < count; i++) {
                if (items[i].name == thisItem) {
                    cout << "\nEnter New Price: Rs ";
                    cin >> thisPrice; 
                    cout << "Price Changed from " << fixed << setprecision(2) << items[i].price << " to " << fixed << setprecision(2) << thisPrice << endl;
                    items[i].price = thisPrice;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cout << "\nItem Not Found in Inventory!\n";
            }
        }

        void viewInventory () {
            float sum = 0.0;

            if (count == 0) {
                cout << "\nInventory is empty.\n";
                return;
            }

            cout << "\n----------------- INVENTORY -----------------\n";
            for (int i = 0; i < count; i++) {
                cout << items[i].name << " --- Rs " << items[i].price << endl;
                sum += items[i].price;
            }
            cout << "\nInventory is Valued at Rs " << fixed << setprecision(2) << sum << endl;
        }

        void generateReceipt() {
            float total = 0.0;
            int quantity;
            string thisItem;

            cout << "\nGenerating Receipt...\n";
            cout << "\nEnter Item Name (or 'done' to exit): ";

            while (true) {
                bool found = false;
                cin.ignore();
                getline(cin, thisItem);

                if (thisItem == "done") break;

                for (int i = 0; i < count; i++) {
                    if (items[i].name == thisItem) {
                        cout << "Enter Quantity: ";
                        cin >> quantity;
                        float itemTotal = items[i].price * quantity;
                        total += itemTotal;
                        cout << quantity << " x " << items[i].name << " @ Rs " << fixed << setprecision(2) << items[i].price << " = Rs " << fixed << setprecision(2) << itemTotal << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Item not found in inventory.\n";
                }
                cout << "Enter next item name (or 'done' to finish): ";
            }
            cout << "\nTotal Bill: Rs " << fixed << setprecision(2) << total << endl;
        }
};

int main () {
    GroceryStore store;
    int choice;
    
    while (true) {
        cout << "\n1. Add Item";
        cout << "\n2. Update Price";
        cout << "\n3. View Inventory";
        cout << "\n4. Generate Receipt";
        cout << "\n5. Exit";
        cout << "\nEnter your Choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "\nExiting\n";
            break;
        }

        switch (choice) {
            case 1:
                store.add(); 
                break;
            case 2:
                store.updatePrice(); 
                break;
            case 3:
                store.viewInventory(); 
                break;
            case 4:
                store.generateReceipt(); 
                break;
            default:
                cout << "\nPlease Enter a Valid Choice!\n";
        }
    }    
    return 0;
}