#include <iostream>
using namespace std;

// Node का स्ट्रक्चर
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List को प्रिंट करने का फंक्शन
void displayList(Node* head) {
    Node* temp = head;
    cout << "\n--- Linked List Elements ---\n";
    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next; // अगले node पर जाएँ
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== SINGLY LINKED LIST DEMO ===\n";

    // 1. तीन अलग-अलग Nodes बनाए
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // 2. Nodes को आपस में कनेक्ट किया
    head->next = second;   // 10 का अगला -> 20
    second->next = third;  // 20 का अगला -> 30
    third->next = NULL;    // 30 का अगला -> NULL (लिस्ट ख़त्म)

    // 3. Linked List को डिस्प्ले किया
    displayList(head);

    return 0;
}