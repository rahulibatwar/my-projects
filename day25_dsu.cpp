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

// Circular Linked List के शुरुआत (Beginning) में Insertion का फंक्शन
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);

    // अगर लिस्ट खाली है
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // खुद को ही पॉइंट करेगा
        cout << "[+] Inserted " << val << " at beginning.\n";
        return;
    }

    // आख़िरी Node ढूंढने के लिए Traverse करें
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Links अपडेट करें
    newNode->next = head;
    temp->next = newNode; // आख़िरी node अब नए node को पॉइंट करेगा
    head = newNode;       // head को अपडेट किया

    cout << "[+] Inserted " << val << " at beginning.\n";
}

// Circular Linked List प्रदर्शित करने का फंक्शन
void displayList(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Current List: ";
    do {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head: " << head->data << ")\n";
}

int main() {
    cout << "=== CIRCULAR LINKED LIST INSERT AT BEGINNING DEMO ===\n\n";

    // 1. Initial List: 10 -> 20 -> 30 -> (Head)
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = head;

    cout << "--- Before Insertion ---\n";
    displayList(head);

    // 2. Insert 5 at Beginning
    cout << "\n--- Inserting Element ---\n";
    insertAtBeginning(head, 5);

    cout << "\n--- After Insertion ---\n";
    displayList(head);

    return 0;
}