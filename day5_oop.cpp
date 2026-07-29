#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    float percentage;

public:
    string name;

    // 1. Parameterized Constructor
    Student(string n, int r, float p) {
        name = n;
        rollNo = r;
        percentage = p;
        cout << "[+] Parameterized Constructor Called for " << name << endl;
    }

    // 2. Copy Constructor (मौजूदा ऑब्जेक्ट 's' से डेटा कॉपी करेगा)
    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        percentage = s.percentage;
        cout << "[+] Copy Constructor Called! Data copied from " << s.name << endl;
    }

    void displayDetails() {
        cout << "Name: " << name << " | Roll No: " << rollNo << " | Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    cout << "=== COPY CONSTRUCTOR DEMO ===" << endl;

    // Object 1: Parameterized Constructor से बनेगा
    Student s1("Rahul", 101, 88.5);

    // Object 2: s1 का डेटा s2 में कॉपी करके बनेगा (Copy Constructor)
    Student s2 = s1; 

    cout << "\n--- Student Details ---" << endl;
    cout << "s1 Details -> ";
    s1.displayDetails();
    
    cout << "s2 Details -> ";
    s2.displayDetails();

    return 0;
}