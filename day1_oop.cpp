#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float percentage;

    void displayDetails() {
        cout << "--- Student Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    // Creating Object 1
    Student s1;
    s1.name = "Rahul";
    s1.rollNo = 101;
    s1.percentage = 88.5;

    // Creating Object 2
    Student s2;
    s2.name = "Priya";
    s2.rollNo = 102;
    s2.percentage = 92.0;

    // Calling Member Function for Object 1     
    s1.displayDetails();    
    // Calling Member Function for Object 2
    s2.displayDetails();


    return 0;
}