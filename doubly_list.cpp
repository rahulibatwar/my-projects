#include <iostream>
using namespace std;

// ==========================================
// 1. DOUBLY NODE STRUCTURE (दो पॉइंटर्स वाला डिब्बा)
// ==========================================
class Node {
public:
    int data;
    Node* next; // अगले नोड का पता
    Node* prev; // पिछले नोड का पता

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL; // शुरुआत में दोनों तरफ खाली रहेगा
    }
};

// ==========================================
// 2. DOUBLY LINKED LIST OPERATIONS
// ==========================================
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // आखिरी में नया नोड जोड़ना (Insert at End)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            cout << "[SUCCESS] " << val << " inserted as Head Node.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode; // पुराने आखिरी नोड को नए नोड से जोड़ें
        newNode->prev = temp; // नए नोड के 'prev' में पुराने आखिरी नोड का पता डालें
        cout << "[SUCCESS] " << val << " inserted at the end.\n";
    }

    // लिस्ट को आगे से पीछे प्रिंट करना (Forward Display)
    void displayForward() {
        if (head == NULL) {
            cout << "\n[INFO] List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "\nForward List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // लिस्ट को पीछे से आगे प्रिंट करना (Reverse Display - असली ताकत)
    void displayReverse() {
        if (head == NULL) {
            cout << "\n[INFO] List is empty!\n";
            return;
        }
        
        // पहले आखिरी नोड तक पहुँचें
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // अब 'prev' पॉइंटर का उपयोग करके पीछे की तरफ आएं
        cout << "Reverse List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev; // पीछे कूदें
        }
        cout << "NULL\n";
    }
};

// ==========================================
// 3. MAIN INTERFACE
// ==========================================
int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\n*** DOUBLY LINKED LIST CORE ***\n";
        cout << "1. Insert at End\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Reverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 2:
                list.displayForward();
                break;
            case 3:
                list.displayReverse();
                break;
            case 4:
                cout << "\nExiting Doubly Linked List Module. Goodbye!\n";
                break;
            default:
                cout << "\n[WARNING] Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}