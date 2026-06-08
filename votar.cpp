#include <iostream>
using namespace std;

class Voter {
public:
    int age;

    // 1️⃣ DEFAULT CONSTRUCTOR: Jab bina value ke object bane
    Voter() {
        age = 18; // Default value set ki
        cout << "[System]: Default Constructor triggered. Age set to: " << age << endl;
    }

    // 2️⃣ PARAMETERIZED CONSTRUCTOR: Jab value pass ki jaye
    Voter(int initialAge) {
        age = initialAge; 
        cout << "[System]: Parameterized Constructor triggered. Age set to: " << age << endl;
    }

    bool checkEligibility() {
        return age >= 18;
    }
};

int main() {
    cout << "--- Constructor Overloading Demo ---" << endl << endl;

    // Pehla object bina parameter ke (Default chalega)
    cout << "Creating Person 1 (Bina parameter ke)..." << endl;
    Voter person1; 
    if (person1.checkEligibility()) {
        cout << "-> Person 1 vote de sakta hai! ✅" << endl << endl;
    }

    // Doosra object parameter ke sath (Parameterized chalega)
    cout << "Creating Person 2 (Parameter 15 ke sath)..." << endl;
    Voter person2(15);
    if (person2.checkEligibility()) {
        cout << "-> Person 2 vote de sakta hai! ✅" << endl << endl;
    } else {
        cout << "-> Person 2 vote nahi de sakta! ❌" << endl << endl;
    }

    return 0;
}