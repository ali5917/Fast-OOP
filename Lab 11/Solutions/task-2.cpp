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
        T *elements;
        int currentIndex;

    public:
        Stack (int c) : currentIndex (0), capacity(c) {
            elements = new T [capacity];
        }

        ~Stack () {
            delete [] elements;
        }

        void push (T item) {
            if (currentIndex == capacity) {
                throw StackOverflowException();
            } else {
                elements[currentIndex] = item;
                cout << "\nElement " << elements[currentIndex] << " pushed at Index: " << currentIndex;
                currentIndex ++;
            }
        }

        void pop () {
            if (currentIndex == 0) {
                throw StackUnderflowException();
            } else {
                cout << "\nElement " << elements[currentIndex - 1] << " popped at Index: " << currentIndex - 1;
                currentIndex --;
            }
        }
};

int main () {
    int capacity = 3;
    Stack <double> myStack (capacity);
    
    try {
        for (int i = 0; i < capacity + 1; i++) {
            myStack.push(i + 2.4);
        }
    } catch (const StackOverflowException &e) {
        cout << "\nPushing to a full Stack: " << e.what() << endl;
    }
    
    try {
        for (int i = 0; i < capacity + 1; i++) {
            myStack.pop();
        }
    } catch (const StackUnderflowException &e) {
        cout << "\nPopping from an empty Stack: " << e.what() << endl;
    }
}