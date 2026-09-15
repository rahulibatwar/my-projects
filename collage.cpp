#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    char name[30];

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
    }

    void putData() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

int main() {
    Employee emp[3]; // Array of 3 objects

    // Input data for 3 employees
    cout << "--- Input Details ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Employee " << (i + 1) << ":" << endl;
        emp[i].getData();
    }

    // Display data of 3 employees
    cout << "\n--- Display Details ---" << endl;
    for (int i = 0; i < 3; i++) {
        emp[i].putData();
    }

    return 0;
}