#include <iostream>
using namespace std;

class person 
{

    protected:
        string name;
        int age;
        person(string n, int a) 
        {

            name = n;
            age = a;
        }
};

class student : public person

{
    int  rollno;
    public:
        student(string n, int a, int r ) : person(n, a) 
        {
            rollno = r;
        }

        void display() 
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Roll No: " << rollno << endl;
        }
}; 
int main() 
{
    student s("rahul", 20, 13212);
    s.display();
    return 0;
}
