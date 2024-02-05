#include <iostream>

using namespace std;

class Temperature {
protected:
    double value;
public:
    Temperature() {
        value = 0;
    }
    Temperature(double v) {
        value = v;
    }
    void setValue(double v) {
        value = v;
    }
    double getValue() const {
        return value;
    }
};

class Celsius : public Temperature {
public:
    Celsius() : Temperature() {}
    Celsius(double v) : Temperature(v) {}
    double toFahrenheit() const {
        return (value * 9 / 5) + 32;
    }
};

class Fahrenheit : public Temperature {
public:
    Fahrenheit() : Temperature() {}
    Fahrenheit(double v) : Temperature(v) {}
    double toCelsius() const {
        return (value - 32) * 5 / 9;
    }
};

int main() {
    int numConversions;
    cout << "How many temperature conversions would you like to perform? ";
    cin >> numConversions;
    for (int i = 0; i < numConversions; i++) {
        char fromUnit, toUnit;
        double value;
        cout << "Enter the temperature value: ";
        cin >> value;
        cout << "Enter the temperature unit (C or F): ";
        cin >> fromUnit;
        cout << "Enter the desired unit (C or F): ";
        cin >> toUnit;
        if (fromUnit == 'C' && toUnit == 'F') {
            Celsius c(value);
            cout << value << " C = " << c.toFahrenheit() << " F" << endl;
        } else if (fromUnit == 'F' && toUnit == 'C') {
            Fahrenheit f(value);
            cout << value << " F = " << f.toCelsius() << " C" << endl;
        } else {
            cout << "Invalid units specified." << endl;
        }
    }
    return 0;
}
