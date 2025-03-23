#include <iostream>
#include<string>
using namespace std;

class Media {
    protected:
        string title;
        int publicationDate;
        string uniqueID;
        string publisher;
        bool available;

    public:
        Media (string t, int p, string i, string pub, bool a) : title(t), publicationDate(p), uniqueID(i), publisher(pub), available(a){}

        virtual void displayInfo(){
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl << endl;
        }

        void checkout(){
            if(available == 0){
                cout << "Item unavailable for checkout2" << endl; 
            }
            else{
                available = 0;
                cout << "Item checked out" << endl;
            }
        }

        void returnItem(){
            available = 1;
            cout << "Item returned" << endl;
        }
        
        string getTitle() { return title; }
        int getDate() { return publicationDate; }
};

class Book: public Media {
    private:
        string author;
        string ISBN;
        int numOfPages;

    public:
        Book (string t, int p, string i, string pu, bool a, string x, string is, int n) : Media(t, p, i, pu, a),author(x), ISBN(is), numOfPages(n) {}

        void displayInfo() override{
            cout << "---- Book Details ----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Author: " << author << endl;
            cout << "ISBN: " << ISBN << endl;
            cout << "Number Of Pages: " << numOfPages << endl << endl;
        }
};

class DVD: public Media {
    private:
        string director;
        string duration;
        float ratings;

    public:
        DVD (string t, int p, string i, string pu, bool a, string x, string is, float n):Media(t, p, i, pu, a), director(x), duration(is), ratings(n) {}

        void displayInfo() override{
            cout << "---- DVD Details ----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Director: " << director << endl;
            cout << "Duration: " << duration << endl;
            cout << "Ratings: " << ratings << endl << endl;
        }
};

class CD: public Media {
    private:
        string artist;
        string genre;
        int numOfTracks;

    public:
        CD (string t, int p, string i, string pu, bool a, string x, string is, int n) : Media(t, p, i, pu, a), artist(x), genre(is), numOfTracks(n) {}

        void displayInfo()override{
            cout << "---- CD Details ----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Artist: " << artist << endl;
            cout << "Genre: " << genre << endl;
            cout << "Number OF Tracks: " << numOfTracks << endl << endl;
        }
};

class Magazine: public Media {
    private:
        int magazineCode;

    public:
        Magazine(string t, int p, string i, string pu, bool a, int m) : Media(t, p, i, pu, a), magazineCode(m) {}

        void displayInfo()override{
            cout << "---- Magazine Details ----" << endl;
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Is Available: " << available << endl;
            cout << "Magazine Code: " << magazineCode << endl;
        }
};

class Library {
    private:
        Media **collection;
        int numItems;

    public:
        Library() : collection(nullptr), numItems(0) {}
        
        ~Library() {
            if(numItems > 0) {
                delete[] collection;
            }
        }

        void addMedia(Media *m) {
            Media** tempCollection = new Media*[numItems + 1];
            
            for(int i = 0; i < numItems; i++) {
                tempCollection[i] = collection[i];
            }
            
            tempCollection[numItems] = m;
            delete[] collection;
            collection = tempCollection;
            
            numItems++;
        }
        
        void searchMedia(string title) {            
            cout << endl << "Searching all media published by title: " << title << endl;

            for(int i = 0; i < numItems; i++) {
                if(collection[i]->getTitle() == title) {
                    cout << "Media Item Found!" << endl;
                    collection[i]->displayInfo();
                    return;
                }
            }
            
            cout << "No media with matching title found!" << endl;
        }
        
        void searchMedia(int year) {
            cout << endl << "Searching all media published on year: " << year << endl;
            bool found = false;
            
            for(int i = 0; i < numItems; i++) {
                if(collection[i]->getDate() == year) {
                    found = true;
                    collection[i]->displayInfo();
                }
            }
            
            if(!found) {
                cout << "No Media with matching publication year found" << endl;
            }
        }
};

int main() {
    Library library;

    Book *b1 = new Book("Oxford Progressive English", 2020, "B002", "Oxford University Press", true, "Rachel Redford", "978-0195477090", 480);
    DVD *d1 = new DVD("Jawani Phir Nahi Ani", 2015, "D002", "ARY Films", true, "Nadeem Baig", "2h 36m", 7.6);
    CD *c1 = new CD("Strings 30", 2019, "C002", "Bilal Maqsood & Faisal Kapadia", true, "Strings", "Pop Rock", 16);
    Magazine *m1 = new Magazine("The Friday Times", 2024, "M002", "Naya Daur Media", true, 1050);


    library.addMedia(b1);
    library.addMedia(d1);
    library.addMedia(c1);
    library.addMedia(m1);

    b1->displayInfo();
    d1->displayInfo();
    c1->displayInfo();
    m1->displayInfo();

    library.searchMedia("The Friday Times");
    library.searchMedia(2022);

    cout << endl;
    b1->checkout();
    b1->returnItem();

    delete b1;
    delete d1;
    delete c1;
    delete m1;

    return 0;
}