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

// Linked List के शुरुआत से Node डिलीट करने का फंक्शन
void deleteFromBeginning(Node* &head) {
    if (head == NULL) {
        cout << "List is already empty!\n";
        return;
    }

    Node* temp = head;       // 1. पहले node को temp में रखा
    head = head->next;       // 2. head को अगले node पर भेजा
    
    cout << "[-] Deleted " << temp->data << " from beginning.\n";
    delete temp;             // 3. पुराने node की मेमोरी फ्री कर दी
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
    cout << "=== LINKED LIST DELETION DEMO ===\n";

    // 1. Initial List: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "\n--- Before Deletion ---\n";
    displayList(head);

    // 2. Delete From Beginning
    cout << "\n--- Deleting Element ---\n";
    deleteFromBeginning(head);

    cout << "\n--- After Deletion ---\n";
    displayList(head);

    return 0;
}