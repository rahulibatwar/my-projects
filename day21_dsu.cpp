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

// Doubly Linked List के अंत (End) में Node इंसर्ट करने का फंक्शन
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    // 1. अगर लिस्ट खाली है
    if (head == NULL) {
        head = newNode;
        cout << "[+] Inserted " << val << " at the end.\n";
        return;
    }

    // 2. आख़िरी Node तक पहुँचें
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 3. Pointers अपडेट करें
    temp->next = newNode;
    newNode->prev = temp;

    cout << "[+] Inserted " << val << " at the end.\n";
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
    cout << "=== DOUBLY LINKED LIST INSERT AT END DEMO ===\n";

    // 1. Initial List: 10 <-> 20
    Node* head = new Node(10);
    Node* second = new Node(20);

    head->next = second;
    second->prev = head;

    cout << "\n--- Before Insertion ---\n";
    displayList(head);

    // 2. Insert at End
    cout << "\n--- Inserting Element ---\n";
    insertAtEnd(head, 30);

    cout << "\n--- After Insertion ---\n";
    displayList(head);

    return 0;
}