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

// Doubly Linked List के अंत (End) से Node डिलीट करने का फंक्शन
void deleteFromEnd(Node* &head) {
    if (head == NULL) {
        cout << "[-] List is empty! Nothing to delete.\n";
        return;
    }

    // Case 1: अगर लिस्ट में केवल 1 ही Node हो
    if (head->next == NULL) {
        cout << "[-] Deleted " << head->data << " from the end.\n";
        delete head;
        head = NULL;
        return;
    }

    // Case 2: आख़िरी Node तक जाएँ
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // सेकंड-लास्ट node का next NULL सेट करें
    temp->prev->next = NULL;

    cout << "[-] Deleted " << temp->data << " from the end.\n";
    delete temp; // आखिरी node की मेमोरी फ़्री की
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
    cout << "=== DOUBLY LINKED LIST DELETE FROM END DEMO ===\n";

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

    // 2. Delete from End
    cout << "\n--- Deleting Element ---\n";
    deleteFromEnd(head);

    cout << "\n--- After Deletion ---\n";
    displayList(head);

    return 0;
}