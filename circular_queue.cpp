#include <iostream>
#define MAX 4  // Chota size rakhte hain taaki overflow jaldi check ho sake
using namespace std;

class CircularQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // 1. ENQUEUE: Element ko circular tarike se insert karna
    void enqueue(int val) {
        // Condition for Full Queue
        if ((rear + 1) % MAX == front) {
            cout << "[Circular Overflow]: Queue full hai! " << val << " add nahi ho sakta." << endl;
            return;
        }

        if (front == -1) front = 0; // Pehla element aane par

        rear = (rear + 1) % MAX; // Circular Increment 🎡
        arr[rear] = val;
        cout << "[Enqueued]: " << val << " at index " << rear << endl;
    }

    // 2. DEQUEUE: Element ko circular tarike se remove karna
    void dequeue() {
        if (front == -1) {
            cout << "[Circular Underflow]: Queue pehle se khali hai!" << endl;
            return;
        }

        cout << "[Dequeued]: " << arr[front] << " removed from index " << front << endl;

        // Agar queue mein ek hi element bacha tha aur wo bhi delete ho gaya
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX; // Circular Increment 🎡
        }
    }

    // 3. DISPLAY: Pure circular loop ko print karna
    void displayQueue() {
        if (front == -1) {
            cout << "Queue Khali Hai!" << endl;
            return;
        }
        cout << "Current Queue State: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- DSA Masterclass: Circular Queue Logic ---" << endl << endl;

    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40); // Yahan array full ho gaya (Size = 4)

    cq.dequeue(); // Index 0 se 10 ko nikal diya, ab Index 0 khali hai!

    cout << "--- Re-using the deleted space ---" << endl;
    cq.enqueue(50); // Linear queue yahan crash ho jata, par circular queue ise Index 0 par bitha dega!

    cq.displayQueue();
    cout << "------------------------------------------" << endl;

    return 0;
}