#include<iostream>
#include<string>
using namespace std;

class Movie {
    private:
        string title, director;
        float duration;
    public:
        Movie(string t, string d, float dur) : title(t), director(d), duration(dur) {}
        string getTitle() { 
            return title; 
        }

        string getDirector() { 
            return director; 
        }
        
        float getDuration() { 
            return duration; 
        }
};

class CinemaHall {
    private:
        int numMovies;
        Movie** movies;
        bool* isScreening;
    public:
        CinemaHall() {
            cout << "Number of movies: ";
            cin >> numMovies;
            cin.ignore();
            movies = new Movie*[numMovies];
            isScreening = new bool[numMovies];
            for(int i = 0; i < numMovies; i++) {
                string t, d, screening;
                float dur;
                cout << "Enter title: ";
                getline(cin, t);

                cout << "Enter director: ";
                getline(cin, d);

                cout << "Enter duration: ";
                cin >> dur;
                cin.ignore();

                movies[i] = new Movie(t, d, dur);

                cout << "Is Screening? (Yes/No): ";
                getline(cin, screening);
                isScreening[i] = ("Yes" == screening) ? true : false;
            }
        }
        ~CinemaHall() {
            for(int i = 0; i < numMovies; i++) {
                delete movies[i];
            }
            delete[] movies;
            delete[] isScreening;
        }
        void displayMovies() {
            for(int i = 0; i < numMovies; i++) {
                cout << i + 1 << ". Title: " << movies[i]->getTitle() << ", Director: " << movies[i]->getDirector() << ", Duration: " << movies[i]->getDuration() << " hours, Is Screening: " << ((isScreening[i]) ? "Yes" : "No") << endl;
            }
            cout << endl;
        }
};

int main() {
    CinemaHall cinema;
    cinema.displayMovies();
    return 0;
}