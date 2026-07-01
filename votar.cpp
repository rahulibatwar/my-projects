#include <iostream>
using namespace std;

// 1️⃣ BASE CLASS (Parent)
class Voter {
protected:
    int age;

public:
    // Constructor
    Voter(int initialAge) {
        age = initialAge;
    }

    // Parent ka base function jise hum override karenge
    void showStatus() {
        cout << "[Standard Voter] Age: " << age << " | Status: Checking via general queue..." << endl;
    }
};

// 2️⃣ DERIVED CLASS (Child)
class SpecialVoter : public Voter {
public:
    int specialPassID;

    // 🔗 CONSTRUCTOR CHAINING: Child apna data le raha hai aur age ko parent constructor ko pass kar raha hai
    SpecialVoter(int initialAge, int passID) : Voter(initialAge) {
        specialPassID = passID;
    }

    // 🎯 FUNCTION OVERRIDING: Same name, same parameters as Parent!
    void showStatus() {
        cout << "[VIP Voter] Pass ID: #" << specialPassID << " | Age: " << age << endl;
        if (age >= 60) {
            cout << "-> Special Status: Senior Citizen VIP Lounge Access Granted! 🌟" << endl;
        } else {
            cout << "-> Special Status: Express Line Access Granted! ⚡" << endl;
        }
    }
};

int main() {
    cout << "--- OOPs Runtime Polymorphism Masterclass ---" << endl << endl;

    // Case 1: Standard Voter Object
    cout << "Creating Regular Voter..." << endl;
    Voter regularPerson(25);
    regularPerson.showStatus(); // Parent wala version chalega
    cout << "------------------------------------------" << endl << endl;

    // Case 2: VIP Voter Object
    cout << "Creating VIP Voter..." << endl;
    SpecialVoter vipPerson(65, 8821);
    vipPerson.showStatus(); // Magic! Overridden Child wala version chalega!

    return 0;
}