#include <iostream>
using namespace std;

// ==========================================
// 1. NODE STRUCTURE
// ==========================================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ==========================================
// 2. LINKED LIST LAYER
// ==========================================
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // 1. शुरुआत में नोड जोड़ना (Insert at Beginning)
    void insertAtBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // नए नोड को पुराने हेड से जोड़ें
        head = newNode;       // अब नया नोड ही हेड बन गया
        cout << "[SUCCESS] " << val << " inserted at the beginning.\n";
    }

    // 2. आखिरी में नोड जोड़ना (Insert at End)
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
        temp->next = newNode;
        cout << "[SUCCESS] " << val << " inserted at the end.\n";
    }

    // 3. वैल्यू के आधार पर नोड को डिलीट करना (Delete by Value)
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "[INFO] List is empty! Nothing to delete.\n";
            return;
        }

        // केस 1: अगर हेड नोड को ही डिलीट करना हो
        if (head->data == val) {
            Node* temp = head;
            head = head->next; // हेड को अगले नोड पर खिसकाएं
            delete temp;       // मेमोरी खाली करें
            cout << "[SUCCESS] Node with value " << val << " deleted.\n";
            return;
        }

        // केस 2: बीच में या आखिरी में से नोड डिलीट करना
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        // अगर वैल्यू लिस्ट में कहीं नहीं मिली
        if (temp->next == NULL) {
            cout << "[INFO] Value " << val << " not found in the list.\n";
            return;
        }

        // नोड को आपस में री-लिंक करें और डिलीट करें
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "[SUCCESS] Node with value " << val << " deleted.\n";
    }

    // 4. पूरी लिस्ट दिखाना
    void display() {
        if (head == NULL) {
            cout << "\n[INFO] Linked List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "\nLinked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ==========================================
// 3. MAIN INTERFACE (With Input Buffer Clearing)
// ==========================================
int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n*** UPGRADED LINKED LIST MODULE ***\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete a Node by Value\n";
        cout << "4. Display Linked List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";

        if (!(cin >> choice)) {
            cout << "\n[ERROR] Please enter a valid number!\n";
            cin.clear();          
            cin.ignore(1000, '\n'); // बफ़र में फंसे गलत इनपुट (जैसे 20-75) को साफ़ करने के लिए
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBegin(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to DELETE: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "\nShutting down Linked List Module. Thank you!\n";
                break;
            default:
                cout << "\n[WARNING] Invalid choice! Select between 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}