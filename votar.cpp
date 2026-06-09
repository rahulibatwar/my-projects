#include <iostream>
using namespace std;

// 1️⃣ PARENT CLASS (Base Class)
class Voter {
protected: // protected likhne se child class is variable ko direct use kar sakti hai
    int age; 

public:
    Voter() {
        age = 18; // Default age
    }

    void setAge(int inputAge) {
        if (inputAge > 0 && inputAge <= 120) {
            age = inputAge;
        }
    }

    int getAge() {
        return age;
    }

    bool checkEligibility() {
        return age >= 18;
    }
};

// 2️⃣ CHILD CLASS (Derived Class) - Syntax dhyan se dekhiye ': public Voter'
class SpecialVoter : public Voter {
public:
    int specialPassID; // Child ka apna naya variable

    void displayVIPReport() {
        // getAge() parent ka function hai, par child ise direct use kar pa raha hai!
        cout << "[VIP Portal]: VIP Pass ID: #" << specialPassID << " | Age: " << getAge() << endl;
        
        if (checkEligibility()) {
            cout << "-> Status: VIP Access Granted! ✅ Direct Entry Allowed." << endl;
        } else {
            cout << "-> Status: Access Denied! ❌ Underage VIP." << endl;
        }
    }
};

int main() {
    cout << "--- OOPs Inheritance Demo ---" << endl << endl;

    // Hum Parent ka nahi, balki Child Class ka object banayenge
    SpecialVoter vipPerson;

    // Child Object se Parent ke functions ko call kiya
    vipPerson.setAge(75); 
    vipPerson.specialPassID = 9901; // Child ka apna data

    // Child ka apna function chalaya
    vipPerson.displayVIPReport();

    return 0;
}