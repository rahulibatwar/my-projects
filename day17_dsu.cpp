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

// Linked List के आखिर (End) से Node डिलीट करने का फंक्शन
void deleteFromEnd(Node* &head) {
    // Case 1: अगर लिस्ट खाली है
    if (head == NULL) {
        cout << "List is already empty!\n";
        return;
    }

    // Case 2: अगर लिस्ट में सिर्फ 1 ही Node है
    if (head->next == NULL) {
        cout << "[-] Deleted " << head->data << " from end.\n";
        delete head;
        head = NULL;
        return;
    }

    // Case 3: 2 या उससे ज़्यादा Nodes होने पर Second Last node तक पहुँचना
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    cout << "[-] Deleted " << temp->next->data << " from end.\n";
    delete temp->next;   // आख़िरी node डिलीट किया
    temp->next = NULL;   // सेकंड-लास्ट node का next NULL किया
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
    cout << "=== LINKED LIST DELETION AT END DEMO ===\n";

    // 1. Initial List: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "\n--- Before Deletion ---\n";
    displayList(head);

    // 2. Delete From End
    cout << "\n--- Deleting Element ---\n";
    deleteFromEnd(head);

    cout << "\n--- After Deletion ---\n";
    displayList(head);

    return 0;
}