#include <iostream>
#include <string>
using namespace std;

class teacher {
    public:
    // properties // attributes
      string name;
      string subject;
      string dept;
      string email;
    private: 
      double salary;

    public:

      // methods // functions
      void changedept(string newdept) {
        dept = newdept;
    }

      //setter 
      void setsalary(double s) {
        salary = s;
    }

       //getter
      double getsalary() {
        return salary;
    }
};

int main() {
    teacher t1;
    t1.name = "John Doe";
    t1.subject = "Mathematics";
    t1.dept = "Computer Science";
    t1.setsalary(75000);

    cout << t1.name << endl;
    cout << t1.getsalary() << endl;

    return 0;
}