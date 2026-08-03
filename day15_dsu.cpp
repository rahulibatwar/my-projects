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

// Linked List के आखिर (End) में नया Node जोड़ने का फंक्शन
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    // अगर लिस्ट खाली है तो नया node ही head बन जाएगा
    if (head == NULL) {
        head = newNode;
        return;
    }

    // आखिरी node तक पहुँचने के लिए temp pointer
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // आखिरी node के next में नया node जोड़ दिया
    temp->next = newNode;
    cout << "[+] Inserted " << val << " at the end.\n";
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
    cout << "=== LINKED LIST INSERT AT END DEMO ===\n";

    // 1. Initial List: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "\n--- Before Insertion ---\n";
    displayList(head);

    // 2. Insert At End
    cout << "\n--- Inserting Elements ---\n";
    insertAtEnd(head, 40);

    cout << "\n--- After Insertion ---\n";
    displayList(head);

    return 0;
}