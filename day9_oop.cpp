#include <iostream>
using namespace std;

class Calculator {
public:
    // 1. Function to calculate Area of Square (1 int argument)
    void calculateArea(int side) {
        int area = side * side;
        cout << "Area of Square (Side: " << side << ") = " << area << endl;
    }

    // 2. Function to calculate Area of Rectangle (2 int arguments)
    void calculateArea(int length, int breadth) {
        int area = length * breadth;
        cout << "Area of Rectangle (" << length << " x " << breadth << ") = " << area << endl;
    }

    // 3. Function to calculate Area of Circle (1 float argument)
    void calculateArea(float radius) {
        float area = 3.14159 * radius * radius;
        cout << "Area of Circle (Radius: " << radius << ") = " << area << endl;
    }
};

int main() {
    cout << "=== FUNCTION OVERLOADING DEMO ===" << endl;

    Calculator calc;

    // C++ खुद तय करेगा कि पैरामीटर्स के आधार पर कौन सा फंक्शन कॉल करना है
    calc.calculateArea(5);          // Calls Square Function
    calc.calculateArea(10, 20);     // Calls Rectangle Function
    calc.calculateArea(7.0f);       // Calls Circle Function

    return 0;
}