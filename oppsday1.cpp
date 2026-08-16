#include <iostream>
#include <string>
using namespace std;

class teacher {
public:
     // non-parameterized constructor
      teacher(){
        dept = "Computer Science";
      }

      // parameterized constructor
      teacher(string n, string s, string d, string e, double sal) {
        name = n;
        subject = s;
        dept = d;
        email = e;
        salary = sal;
      } 

    // properties // attributes
      string name;
      string subject;
      string dept;
      string email;
      double salary;
      // methods // functions
      void changedept(string newdept) {
        dept = newdept;
      }
      void getinfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
        cout << "Email: " << email << endl;
        cout << "Salary: $" << salary << endl;
      }
    };

int main() {
    teacher t1("John Doe", "Data Structures", "Computer Science", "john.doe@university.edu", 75000);
    t1.getinfo();
    return 0;
}