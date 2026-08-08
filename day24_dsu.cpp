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

// Circular Linked List प्रदर्शित करने का फंक्शन
void displayList(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";
    
    // do-while लूप का इस्तेमाल ताकि वापस head पर पहुँचने पर लूप रुक जाए
    do {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    } while (temp != head);
    
    cout << "(Back to Head: " << head->data << ")\n";
}

int main() {
    cout << "=== SINGLY CIRCULAR LINKED LIST CREATION & TRAVERSAL ===\n\n";

    // 1. Nodes बनाना
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // 2. Links सेट करना (Circular Pattern)
    head->next = second;
    second->next = third;
    third->next = head; // आख़िरी Node का next वापस head को पॉइंट करेगा

    // 3. Traversal
    displayList(head);

    return 0;
}