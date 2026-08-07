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

// Doubly Linked List के शुरुआत से Node डिलीट करने का फंक्शन
void deleteFromBeginning(Node* &head) {
    if (head == NULL) {
        cout << "[-] List is empty! Nothing to delete.\n";
        return;
    }

    Node* temp = head;
    head = head->next; // head को अगले node पर ले जाएँ

    // अगर लिस्ट में अभी भी elements बचे हैं
    if (head != NULL) {
        head->prev = NULL; // नए head के prev pointer को NULL सेट करें
    }

    cout << "[-] Deleted " << temp->data << " from the beginning.\n";
    delete temp; // मेमोरी फ़्री की
}

// Forward Traversal प्रदर्शित करने का फंक्शन
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
    cout << "=== DOUBLY LINKED LIST DELETE FROM BEGINNING DEMO ===\n";

    // 1. Initial List: 10 <-> 20 <-> 30
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "\n--- Before Deletion ---\n";
    displayList(head);

    // 2. Delete from Beginning
    cout << "\n--- Deleting Element ---\n";
    deleteFromBeginning(head);

    cout << "\n--- After Deletion ---\n";
    displayList(head);

    return 0;
}