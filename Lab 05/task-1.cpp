#include<iostream>
#include<string>
using namespace std;

class Car {
	private:
		int regNum;
		string model;
		string owner;
	public:
		Car (int r, string m, string o) : regNum(r), model(m), owner(o) {}
		
		Car (Car &obj) {
			regNum = obj.regNum;
			model = obj.model;
			cout << "\nEnter New Owner: ";
			getline(cin, owner);
		}
		
		void displayDetails() {
			cout << "\n\nRegisteration Number: " << regNum;
			cout << "\nModel: " << model;
			cout << "\nOwner Name: " << owner << endl;
		}
};

int main () {
	Car car1(123, "GLI 2018","Ali Kashif");
	Car car2(car1);
	

	car1.displayDetails();
	car2.displayDetails();

	return 0;
}