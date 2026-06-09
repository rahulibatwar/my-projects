#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// 🎯 FUNCTION: Naya element shuruat (Head) mein jodne ke liye
// Yahan Node* &head (Reference pointer) use kiya hai taaki main ka head update ho sake
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val); // 1. Naya node banaya
    newNode->next = head;          // 2. Naye node ko purane head se joda
    head = newNode;                // 3. Head ko naye node par shifted kiya
    cout << "[Inserted]: " << val << " at the beginning." << endl;
}

// List ko print karne ka function
void displayList(Node* head) {
    Node* temp = head;
    cout << "Final Linked List Chain: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- DSA Dynamic Linked List Implementation ---" << endl << endl;

    Node* head = NULL; // Shuruat mein list bilkul khali (Empty) hai

    // 🚀 Dynamically data insert kar rahe hain
    insertAtHead(head, 30); // List: 30 -> NULL
    insertAtHead(head, 20); // List: 20 -> 30 -> NULL
    insertAtHead(head, 10); // List: 10 -> 20 -> 30 -> NULL
    insertAtHead(head, 5);  // List: 5 -> 10 -> 20 -> 30 -> NULL

    cout << "-----------------------------------------------" << endl;
    
    // Final output display karenge
    displayList(head);

    return 0;
}