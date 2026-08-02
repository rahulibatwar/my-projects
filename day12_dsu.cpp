#include <iostream>
using namespace std;

#define SIZE 3

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // 1. Enqueue Operation (Add Element)
    void enqueue(int val) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! (Queue Full)\n";
        } else {
            if (front == -1) front = 0; // First Element
            rear++;
            arr[rear] = val;
            cout << "[+] Enqueued: " << val << endl;
        }
    }

    // 2. Dequeue Operation (Remove Element)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! (Queue Empty)\n";
        } else {
            cout << "[-] Dequeued: " << arr[front] << endl;
            front++;
        }
    }

    // Display Queue Elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty!\n";
        } else {
            cout << "\n--- Current Queue Elements ---\n[ ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << "]\n-----\n";
        }
    }
};

int main() {
    cout << "=== QUEUE DATA STRUCTURE DEMO ===\n";

    Queue q;

    // Enqueue Elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Overflow Test
    q.enqueue(40);

    q.display();

    // Dequeue Element (First In First Out)
    q.dequeue();
    q.display();

    return 0;
}