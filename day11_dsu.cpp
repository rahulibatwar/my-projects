#include <iostream>
using namespace std;

#define MAX 3 // Stack की मैक्सिमम साइज 3 रखी है

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { 
        top = -1; // शुरुआत में Stack खाली है
    }

    // 1. PUSH Operation
    void push(int val) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! (Stack फुल हो चुका है)\n";
        } else {
            top++;
            arr[top] = val;
            cout << "[+] Pushed: " << val << endl;
        }
    }

    // 2. POP Operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! (Stack खाली है)\n";
        } else {
            int poppedVal = arr[top];
            top--;
            cout << "[-] Popped: " << poppedVal << endl;
        }
    }

    // Display Stack Elements
    void display() {
        if (top < 0) {
            cout << "Stack खाली है!\n";
        } else {
            cout << "\n--- Current Stack Elements ---\n";
            for (int i = top; i >= 0; i--) {
                cout << "| " << arr[i] << " |\n";
            }
            cout << "-----\n";
        }
    }
};

int main() {
    cout << "=== STACK DATA STRUCTURE DEMO ===\n";

    Stack s;

    // Push Operations
    s.push(10);
    s.push(20);
    s.push(30);

    // Overflow चेक करने के लिए चौथा एलिमेंट पुश करते हैं
    s.push(40);

    // Current Stack Display
    s.display();

    // Pop Operations
    s.pop();
    s.display();

    return 0;
}