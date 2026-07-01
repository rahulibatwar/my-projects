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

void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 🎯 INTERVIEW SPECIAL: Linked List ko reverse karne ka function
void reverseList(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // 1. Agle node ka address safe kiya
        curr->next = prev;     // 2. Current node ka rasta piche mod diya (Main Step!)
        
        // 3. Pointers ko ek-ek kadam aage badhaya
        prev = curr;
        curr = nextNode;
    }
    head = prev; // 4. Aakhiri mein 'prev' hi hamara naya head ban chuka hoga
    cout << "[System Notification]: Linked List successfully reversed in-place!" << endl;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "--- DSA Google Interview Challenge: Reverse Linked List ---" << endl << endl;

    Node* head = NULL;

    // Ek achhi badi list banate hain: 10 -> 20 -> 30 -> 40
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    
    cout << "Original ";
    displayList(head);
    cout << "------------------------------------------------------------" << endl;

    // 🔥 Reversing operation trigger karte hain
    reverseList(head);
    
    cout << "Reversed ";
    displayList(head);
    cout << "------------------------------------------------------------" << endl;

    return 0;
}