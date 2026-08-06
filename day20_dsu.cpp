#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List के शुरुआत में Node इंसर्ट करने का फंक्शन
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);

    // अगर लिस्ट खाली नहीं है, तो पुराने head का prev नए node पर सेट करें
    if (head != NULL) {
        head->prev = newNode;
    }

    newNode->next = head; // नए node का next पुराना head बनेगा
    head = newNode;       // head अब नए node को पॉइंट करेगा

    cout << "[+] Inserted " << val << " at the beginning.\n";
}

// Forward Traversal डिस्प्ले करने का फंक्शन
void displayList(Node* head) {
    Node* temp = head;
    cout << "Current List: NULL <-> ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== DOUBLY LINKED LIST INSERT AT BEGINNING DEMO ===\n";

    // 1. Initial List: 10 <-> 20
    Node* head = new Node(10);
    Node* second = new Node(20);

    head->next = second;
    second->prev = head;

    cout << "\n--- Before Insertion ---\n";
    displayList(head);

    // 2. Insert at Beginning
    cout << "\n--- Inserting Element ---\n";
    insertAtBeginning(head, 5);

    cout << "\n--- After Insertion ---\n";
    displayList(head);

    return 0;
}