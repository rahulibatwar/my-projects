#include <iostream>
using namespace std;

// Parent Class
class Animal {
public:
    // virtual Keyword का इस्तेमाल
    virtual void makeSound() {
        cout << "Animal makes a sound..." << endl;
    }
};

// Child Class
class Dog : public Animal {
public:
    // Parent Class के फंक्शन को Override किया जा रहा है
    void makeSound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

int main() {
    cout << "=== VIRTUAL FUNCTION & OVERRIDING DEMO ===" << endl;

    // Parent Class का Pointer
    Animal* ptr;

    // Child Class का Object
    Dog myDog;

    // Pointer में Child Class का Address असाइन किया
    ptr = &myDog;

    // Function Call (Virtual Keyword की वजह से Child Class वाला Function चलेगा)
    ptr->makeSound();

    return 0;
}