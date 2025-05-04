#include <iostream>
#include <string>
using namespace std;

class StackOverflowException : public exception {
    public:
        const char* what () const noexcept override {
            return "StackOverflowException - Stack is full!";
        }
};

class StackUnderflowException : public exception {
    public:
        const char* what () const noexcept override {
            return "StackUnderflowException - Stack is empty!";
        }
};

template<typename T>
class Stack {
    private:
        int capacity;
        T elements[capacity];
        int currentIndex;

    public:
        Stack (int c) : currentIndex (0), capacity(c) {}

        void push (T item) {
            if (currentIndex == capacity) {
                throw StackOverflowException();
            } else {
                elements[currentIndex] = item;
                cout << "\nElement" << elements[currentIndex] << " pushed at index " << currentIndex;
                currentIndex ++;
            }
        }

    public:


};