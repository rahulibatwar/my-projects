#include <iostream>
#include <string>
using namespace std;

class teacher {
private:
        double salary;  


public:

        string name;
        string subject;
        string dept;
     // non-parameterized constructor
      teacher(){
        dept = "Computer Science";
        salary = 0;   
      }

      // parameterized constructor
      teacher(string name, string subject, string dept, double salary) {
        this->name = name;
        this->subject = subject;
        this->dept = dept;
        this->salary = salary;
      } 

      // methods // functions
      void changedept(string newdept) {
        dept = newdept;
      }

      void getinfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
      }

};

int main() {
    teacher t1("John Doe", "Data Structures", "Computer Science", 75000);
    t1.getinfo();

    return 0;
}