#include <iostream> // C ke stdio.h ki jagah C++ mein iostream use hota hai
using namespace std;

// Ek 'Voter' naam ki Class banayi (Blueprint)
class Voter {
public:
    // Properties (Variables)
    int age;

    // Method (Function jo class ke andar hota hai)
    bool checkEligibility() {
        if (age >= 18) {
            return true; // C++ mein built-in true/false boolean hota hai
        } else {
            return false;
        }
    }
};

int main() {
    // Class ka ek Real Object banaya
    Voter person1;

    cout << "--- Welcome to C++ OOPs Voter Checker ---" << endl;
    cout << "Person 1 ki age enter kijiye: ";
    
    // User se input lene ka modern C++ tarika
    cin >> person1.age; 

    // Object ke andar ke function ko call kiya
    if (person1.checkEligibility()) {
        cout << "Aap vote de sakte hain! (C++ Object Verified)" << endl;
    } else {
        cout << "Maaf kijiye, aap abhi vote nahi de sakte." << endl;
    }

    return 0;
}