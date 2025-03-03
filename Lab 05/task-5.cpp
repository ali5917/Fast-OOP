#include<iostream>
#include<string>
using namespace std;

class TourGuide {
    private:
        string name;
        int experience;
        string specialization;
    public:
        TourGuide(string n, int y, string s) : name(n), experience(y), specialization(s) {}
        string getName() { 
            return name; 
        }

        int getExperience() { 
            return experience; 
        }

        string getSpecialization() { 
            return specialization; 
        }
};

class TravelAgency {
    private:
        int numGuides;
        TourGuide ** tourGuides;
    public:
        TravelAgency() {
            numGuides = 0;
            tourGuides = nullptr;
        }

        void addTourGuide(TourGuide* tourGuide) {
            TourGuide ** temp = new TourGuide* [numGuides + 1];
            for(int i = 0; i < numGuides; i++) {
                temp[i] = tourGuides[i];
            }
            temp[numGuides] = tourGuide;
            delete[] tourGuides;
            tourGuides = temp;
            numGuides += 1;
            cout << tourGuide->getName() << " added to Tour Guides!" << endl << endl;
        }

        void removeTourGuide() {
            string name;
            cout << "Tour Guide Name to be removed: ";
            getline(cin, name);
            bool found = false;
            int index;
            for(int i = 0; i < numGuides; i++) {
                if(name == tourGuides[i]->getName()) {
                    found = true;
                    index = i;
                }
            }
            if(!found) {
                cout << "Tour Guide " << name << " not found." << endl;
                return;
            }
            if(numGuides == 1) {
                delete[] tourGuides;
                tourGuides = nullptr;
            } else{
                TourGuide** temp = new TourGuide*[numGuides - 1];
                for(int i = 0; i < index; i++) {
                    temp[i] = tourGuides[i];
                }
                for(int i = index; i < numGuides; i++) {
                    temp[i - 1] = tourGuides[i];
                }
                delete[] tourGuides;
                tourGuides = temp;
            }
            numGuides -= 1;
            cout << "Tour Guide " << name << " removed!" << endl << endl;
        }

        void displayTourGuides() {
            for(int i = 0; i < numGuides; i++) {
                cout << i + 1 << ". Name: " << tourGuides[i]->getName() << ", Years of Experience: " << tourGuides[i]->getExperience() << ", Specialization: " << tourGuides[i]->getSpecialization() << endl;
            }
            cout << endl;
        }
        ~TravelAgency() {
            delete[] tourGuides;
        }
};

int main() {
    TravelAgency FASTAgency;
    TourGuide* ali = new TourGuide("Ali", 8, "Hill sites Exploration");
    TourGuide* ismail = new TourGuide("Ismail", 4, "Food Exploration");
    TourGuide* hammad = new TourGuide("Hammad", 2, "Sea side Exploration");

    FASTAgency.addTourGuide(ali);
    FASTAgency.addTourGuide(ismail);
    FASTAgency.addTourGuide(hammad);
    FASTAgency.displayTourGuides();
    FASTAgency.removeTourGuide();
    FASTAgency.displayTourGuides();

    delete ali, ismail, hammad;
    return 0;
}