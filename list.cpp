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

// Purana Function: Head par jodne ke liye
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// 🎯 DADA LOGIC: Aakhiri (Tail) mein element jodne ke liye
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val); // 1. Naya node banaya

    // Base Case: Agar list pehle se khali hai
    if (head == NULL) {
        head = newNode;
        cout << "[Tail Inserted]: " << val << " became the Head (List was empty)." << endl;
        return;
    }

    // 2. Traversal: Ek temporary pointer ko aakhiri node tak le jayenge
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Agle node par jump
    }

    // 3. Connection: Aakhiri node ke next mein naya node jod diya
    temp->next = newNode;
    cout << "[Tail Inserted]: " << val << " at the very end." << endl;
}

// List ko print karne ka function
void displayList(Node* head) {
    Node* temp = head;
    cout << "Final Linked List Chain: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl << endl;
}

int main() {
    cout << "--- DSA Linked List Masterclass: Head & Tail Insertion ---" << endl << endl;

    Node* head = NULL; // Shuruat mein empty list

    // Step 1: Pehle dono tarike se insert karke check karte hain
    insertAtTail(head, 10);  // List: 10 -> NULL (Khali thi isliye pehla bana)
    insertAtTail(head, 20);  // List: 10 -> 20 -> NULL
    insertAtTail(head, 30);  // List: 10 -> 20 -> 30 -> NULL

    cout << "--- Current List State ---" << endl;
    displayList(head);

    // Step 2: Ab mixture check karte hain (Head aur Tail dono sath mein)
    cout << "--- Mixing Head and Tail Insertions ---" << endl;
    insertAtHead(head, 5);   // Head par daala -> List ke aage lag jayega
    insertAtTail(head, 40);  // Tail par daala -> List ke piche lag jayega

    cout << "--------------------------------------------------------" << endl;
    displayList(head);

    return 0;
}