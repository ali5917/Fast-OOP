#include <iostream>
using namespace std;

class Activity {
    public:
        virtual double calculateCaloriesBurned() = 0;

};

class Running : public Activity {
    private:
        double distance;
        double time;

    public:
        Running(double d, double t) : distance(d), time(t) {}
       
        double calculateCaloriesBurned() {
            return (distance * 60);
        }
};

class Cycling : public Activity {
    private:
        double speed;
        double time;

    public:
        Cycling(double s, double t) : speed(s), time(t) {}
        
        double calculateCaloriesBurned() {
            return (speed * time * 40);
        }
};

int main() {
    Cycling c(20, 5);
    Running r(10, 20);

    cout << "Calculated Calories burnt by Running: "; 
    cout << r.calculateCaloriesBurned() << endl;
    
    cout << "Calculated Calories burnt by Cycling: "; 
    cout << c.calculateCaloriesBurned() << endl;
    
}