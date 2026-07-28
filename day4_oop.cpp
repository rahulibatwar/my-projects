#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    float percentage;

public:
    string name;

    // 1. Default Constructor (कोई parameter नहीं)
    Student() {
        name = "Unknown";
        rollNo = 0;
        percentage = 0.0;
        cout << "[+] Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor (3 parameters)
    Student(string n, int r, float p) {
        name = n;
        rollNo = r;
        percentage = p;
        cout << "[+] Parameterized Constructor Called for " << name << endl;
    }

    void displayDetails() {
        cout << "Name: " << name << " | Roll No: " << rollNo << " | Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    cout << "=== CONSTRUCTOR OVERLOADING DEMO ===" << endl;

    // Object 1: बिना पैरामीटर के (Default Constructor कॉल होगा)
    Student s1;
    
    // Object 2: पैरामीटर्स के साथ (Parameterized Constructor कॉल होगा)
    Student s2("Rahul", 101, 88.5);

    cout << "\n--- Student Details ---" << endl;
    s1.displayDetails();
    s2.displayDetails();

    return 0;
}