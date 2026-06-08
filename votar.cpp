#include <iostream>
using namespace std;

class Voter {
public:
    int age;

    // 1️⃣ CONSTRUCTOR: Object bante waqt chalega
    Voter(int initialAge) {
        age = initialAge;
        cout << "[Constructor]: Object created with Age: " << age << endl;
    }

    // 2️⃣ DESTRUCTOR: Object destroy hote waqt automatic chalega!
    ~Voter() {
        cout << "[Destructor]: Memory clean up done! Object with Age " << age << " is now destroyed." << endl;
    }

    bool checkEligibility() {
        return age >= 18;
    }
};

int main() {
    cout << "--- Destructor Life-Cycle Demo ---" << endl << endl;

    // Hum blocks {} ka use karke ek chhota sa temporary area (scope) banayenge
    {
        cout << "Entering inside temporary block..." << endl;
        Voter person1(22); 
        
        if (person1.checkEligibility()) {
            cout << "-> Person 1 eligible hai!" << endl;
        }
        cout << "Exiting temporary block..." << endl;
    } // 🎯 JAISE HI YAHAN BLOCK KHATAM HOGA, person1 KI LIFE KHATAM HO JAYEGI AUR DESTRUCTOR CHALEGA!

    cout << endl << "Back in main function. Program ending now..." << endl;
    return 0;
}