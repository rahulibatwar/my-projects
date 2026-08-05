#include <iostream>
using namespace std;

// Doubly Linked List का Node
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

// Forward Direction में प्रिंट करने का फंक्शन
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward Traversal:  NULL <-> ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Backward Direction में प्रिंट करने का फंक्शन
void displayBackward(Node* head) {
    if (head == NULL) return;

    // 1. सबसे पहले आख़िरी Node तक पहुँचे
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 2. अब prev pointer का इस्तेमाल करके पीछे की तरफ आएँ
    cout << "Backward Traversal: NULL <-> ";
    while (temp != NULL) {
        cout << "[" << temp->data << "] <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== DOUBLY LINKED LIST DEMO ===\n";

    // 1. 3 Nodes क्रिएट किए
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // 2. Next Pointers कनेक्ट किए
    head->next = second;
    second->next = third;

    // 3. Prev Pointers कनेक्ट किए
    second->prev = head;
    third->prev = second;

    // 4. Traversal
    displayForward(head);
    displayBackward(head);

    return 0;
}