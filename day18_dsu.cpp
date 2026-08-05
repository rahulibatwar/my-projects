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

// Linked List में Element सर्च करने का फंक्शन
void searchElement(Node* head, int target) {
    Node* temp = head;
    int pos = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == target) {
            cout << "[+] Element " << target << " found at Position " << pos << "!\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        cout << "[-] Element " << target << " NOT found in the list!\n";
    }
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
    cout << "=== LINKED LIST SEARCHING DEMO ===\n";

    // 1. Initial List: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    displayList(head);

    // 2. Search Operations
    cout << "\n--- Searching Elements ---\n";
    searchElement(head, 30); // Present
    searchElement(head, 99); // Not Present

    return 0;
}