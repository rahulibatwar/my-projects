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

// Linked List के शुरुआत में नया Node जोड़ने का फंक्शन
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head; // नए node का next पुराने head की तरफ इशारा करेगा
    head = newNode;       // head को अपडेट करके नए node पर लाएंगे
    cout << "[+] Inserted " << val << " at the beginning.\n";
}

// Linked List डिस्प्ले करने का फंक्शन
void displayList(Node* head) {
    Node* temp = head;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== LINKED LIST INSERTION DEMO ===\n";

    // 1. Initial Head
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "\n--- Before Insertion ---\n";
    displayList(head);

    // 2. Insert At Beginning
    cout << "\n--- Inserting Elements ---\n";
    insertAtBeginning(head, 5);

    cout << "\n--- After Insertion ---\n";
    displayList(head);

    return 0;
}