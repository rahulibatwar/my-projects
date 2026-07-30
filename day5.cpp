#include <iostream>
using namespace std;

class Account {
private:
    int balance;

public:
    // 1. Parameterized Constructor
    Account(int b) {
        balance = b;
        cout << "Account created with balance: " << balance << endl;
    }

    // 2. Destructor
    ~Account() {
        cout << "Account object destroyed and memory freed!" << endl;
    }
};

int main() {
    Account acc1(5000); // Triggers Parameterized Constructor
    return 0;           // Triggers Destructor automatically at the end
}