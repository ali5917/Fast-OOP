#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileException: public exception {
    public: 
        virtual const char* what () const noexcept override {
            return "FileException - File not found or Access denied!";
        }
};

class FileNotFoundException: public FileException {
    public: 
        const char* what () const noexcept override {
            return "FileNotFoundException - File not found!";
        }
};

class PermissionDeniedException: public FileException {
    public: 
        const char* what () const noexcept override {
            return "PermissionDeniedException - Access denied!";
        }
};

void readFile (const string &fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        throw FileNotFoundException();
    } else if (fileName == "secret.txt") {
        throw PermissionDeniedException();
    }
    file.close();
}

int main () {
    string fileName = "secret.txt";
    try {
        readFile(fileName);
    } 
    catch (const FileException &e) {
        cout << "Reading '" << fileName << "': " << e.what() << endl;
    }
}