#include <iostream>
using namespace std;

// Level 1: Base Class
class Student {
public:
    int rollNo;
    void setRollNo(int r) {
        rollNo = r;
    }
};

// Level 2: Derived Class from Student
class Exam : public Student {
public:
    float marks1, marks2;
    void setMarks(float m1, float m2) {
        marks1 = m1;
        marks2 = m2;
    }
};

// Level 3: Derived Class from Exam (Multilevel)
class Result : public Exam {
public:
    void displayResult() {
        float total = marks1 + marks2;
        cout << "Roll No     : " << rollNo << endl; // Level 1 का variable
        cout << "Subject 1   : " << marks1 << endl; // Level 2 का variable
        cout << "Subject 2   : " << marks2 << endl; // Level 2 का variable
        cout << "Total Marks : " << total << endl;
    }
};

int main() {
    cout << "=== MULTILEVEL INHERITANCE DEMO ===" << endl;

    // सिर्फ सबसे आखिरी Child Class (Result) का Object बनाएँगे
    Result studentResult;

    // Level 1 का फंक्शन कॉल
    studentResult.setRollNo(101);

    // Level 2 का फंक्शन कॉल
    studentResult.setMarks(88.0, 92.5);

    cout << "\n--- Student Final Scorecard ---" << endl;
    // Level 3 का फंक्शन कॉल
    studentResult.displayResult();

    return 0;
}