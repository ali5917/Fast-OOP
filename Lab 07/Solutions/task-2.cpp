#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape {
    protected:
        int position;
        string color;
        float borderThickness;

    public:
        Shape(int p, string c, float b) : position(p), color(c), borderThickness(b) {} 
        
        virtual void draw() {
            cout << "Drawing Shape" << endl;
        }
        
        virtual void calculateArea() {
            cout << "Calculating area" << endl;
        }
        
        virtual void calculatePerimeter() {
            cout << "Calculating perimeter" << endl;
        }
};

class Circle: public Shape {
    private:
        float radius;
        int centerPosititon;

    public:
        Circle(int p, string c, float b, float r, int cPosition) : Shape(p, c, b) ,radius(r), centerPosititon(cPosition) {}
        
        void draw() override {
            cout << "Drawing Circle..." << endl;
        }
        
        void calculateArea() override {
            cout << "Area of Circle: " << M_PI * pow(radius, 2) << endl;
        } 
       
        void calculatePerimeter() override {
            cout << "Perimeter of Circle: " << 2 * M_PI * radius << endl;
        }
};

class Rectangle: public Shape {
    private:
        float width, height;
        int topLeftCorner;

    public:
        Rectangle(int p, string c, float b, float w, float h, int t) : Shape(p, c, b) ,width(w), height(h), topLeftCorner(t) {}
        
        void draw() override {
            cout << "Drawing Rectangle" << endl;
        }
        
        void calculateArea() override {
            cout << "Area of Rectangle: " << width * height << endl;
        } 
    
        void calculatePerimeter() override {
            cout << "Perimeter of Rectangle: " << (2 * width) + (2 * height) << endl;
        }
};

class Triangle: public Shape {
    private:
        float height;
        float side1, side2, side3;

    public:
        Triangle(int p, string c, float b, float s1, float s2, float s3, float h1) : Shape(p, c, b), side1(s1), side2(s2), side3(s3), height(h1) {}
        
        void draw() override {
            cout << "Drawing Triangle" << endl;
        }
        
        void calculateArea() override {
            cout << "Area of Triangle: " << 0.5 * side1 * height << endl;
        } 
        
        void calculatePerimeter() override {
            cout << "Perimeter of Triangle: " << side1 + side2 + side3  << endl;
        }
};

class Polygon: public Shape {
    private:
        int numSides;
        float side;

    public:
        Polygon(int p, string c, float b, float s, int n) : Shape(p, c, b), numSides(n), side(s) {}
        
        void draw() override {
            cout << "Drawing Polygon" << endl;
        }
        
        void calculateArea() override {
            cout << "Area of Polygon: " << (numSides * pow(side, 2)) / (4 * tan(M_PI / numSides)) << endl;
        } 
        
        void calculatePerimeter() override {
            cout << "Perimeter of Polygon: " << side * numSides << endl;
        }
};

int main() {
    Shape* shapes[4];

    shapes[0] = new Circle(0, "Red", 2.0, 5.0, 10);
    shapes[1] = new Rectangle(1, "Blue", 1.5, 4.0, 6.0, 5);
    shapes[2] = new Triangle(2, "Green", 1.0, 3.0, 4.0, 5.0, 2.5);
    shapes[3] = new Polygon(3, "Yellow", 1.2, 4.0, 6);

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        shapes[i]->calculatePerimeter();
        cout << "\n";
        delete shapes[i];
    }

    return 0;
}