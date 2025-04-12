#include <iostream>
#include <string>
using namespace std;

class Humidity;

class Temperature {
    private:
        float temperature;

    public:
        Temperature(float t) : temperature(t) {}
        float getTemperature() const { return temperature; }

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity {
    private:
        float humidity;

    public:
        Humidity(float h) : humidity(h) {}
        float getHumidity() const { return humidity; }

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h) {
    return (t.temperature + 0.33 * h.humidity - 4);
}

int main() {
    Temperature t(32);
    Humidity h(85);
    cout << "Temperature: " << t.getTemperature() << ", Humidity: " << h.getHumidity(); 
    cout << "\nCalculated Heat Index: " << calculateHeatIndex(t,h);
    return 0;
}