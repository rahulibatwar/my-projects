#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    float percentage;

public:
    string name;
    string collegeName;

    // 1. Parameterized Constructor
    Student(string n, string c, int r, float p) {
        name = n;
        collegeName = c;
        rollNo = r;
        percentage = p;
        cout << "[+] Constructor: Object created for " << name << endl;
    }

    // Member Function to Display Details
    void displayDetails(int rank) {
        cout << "\n-----------------------------------" << endl;
        cout << "   Top 3 Student - Rank #" << rank << endl;
        cout << "-----------------------------------" << endl;
        cout << "College    : " << collegeName << endl;
        cout << "Name       : " << name << endl;
        cout << "Roll No    : " << rollNo << endl;
        cout << "Percentage : " << percentage << "%" << endl;
    }

    // 2. Destructor (जब ऑब्जेक्ट का काम खत्म होगा तब रन होगा)
    ~Student() {
        cout << "[-] Destructor: Memory freed for " << name << endl;
    }
};

int main() {
    cout << "=== COLLEGE TOPPER SELECTION ===" << endl;

    // Objects बनाते ही Constructor अपने आप कॉल होगा और डेटा सेट हो जाएगा
    Student s1("Rahul", "Government Polytechnic", 101, 88.5);
    Student s2("Priya", "Government Polytechnic", 102, 92.0);
    Student s3("Amit", "Government Polytechnic", 103, 78.5);

    // Display Information
    s1.displayDetails(1);
    s2.displayDetails(2);
    s3.displayDetails(3);

    cout << "\n=== END OF MAIN FUNCTION ===" << endl;

    return 0;
}