#include <iostream>
using namespace std;

// 1. Parent Class (Base Class)
class Person {
public:
    string name;
    int age;

    void setPersonInfo(string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonInfo() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << " years" << endl;
    }
};

// 2. Child Class (Derived Class) - Parent Class से inherit कर रही है
class Student : public Person {
public:
    int rollNo;
    float percentage;

    void setStudentInfo(int r, float p) {
        rollNo = r;
        percentage = p;
    }

    void displayStudentInfo() {
        // Person Class के variables (name, age) को यहाँ डायरेक्ट एक्सेस किया जा रहा है
        displayPersonInfo(); 
        cout << "Roll No    : " << rollNo << endl;
        cout << "Percentage : " << percentage << "%" << endl;
    }
};

int main() {
    cout << "=== SINGLE INHERITANCE DEMO ===" << endl;

    // केवल Child Class (Student) का ऑब्जेक्ट बनाएँगे
    Student s1;

    // Parent Class के फंक्शन्स का इस्तेमाल
    s1.setPersonInfo("Rahul", 19);

    // Child Class के फंक्शन्स का इस्तेमाल
    s1.setStudentInfo(101, 88.5);

    cout << "\n--- Student Complete Details ---" << endl;
    s1.displayStudentInfo();

    return 0;
}