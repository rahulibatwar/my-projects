#include <iostream>
#define MAX 5
using namespace std;

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // 1. ENQUEUE: Element ko piche (Rear) se insert karna
    void enqueue(int val) {
        if (rear == MAX - 1) {
            cout << "[Queue Overflow]: Line full hai! Cannot add " << val << endl;
            return;
        }
        
        if (front == -1) front = 0; // Agar pehla element aa raha hai toh front ko 0 par laye
        
        rear++;
        arr[rear] = val;
        cout << "[Enqueued]: " << val << " added to the queue." << endl;
    }

    // 2. DEQUEUE: Element ko aage (Front) se remove karna
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "[Queue Underflow]: Line pehle se khali hai!" << endl;
            return;
        }
        
        cout << "[Dequeued]: " << arr[front] << " removed from front." << endl;
        front++; // Front ko ek kadam aage badha diya
    }

    // 3. FRONT: Sabse aage ka element dekhna
    int getFront() {
        if (front == -1 || front > rear) {
            cout << "[Notice]: Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // 4. ISEMPTY: Verification
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    cout << "--- DSA Masterclass: Array-Based Queue Implementation ---" << endl << endl;

    Queue q;

    // Line mein log aana shuru huye
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Element at Front: " << q.getFront() << endl; // 10 hona chahiye kyunki wo pehle aaya tha
    cout << "--------------------------------------------------" << endl;

    // Pehle insaan ko ticket mil gayi, line se bahar nikla
    q.dequeue();
    cout << "New Element at Front: " << q.getFront() << endl; // Ab 20 hona chahiye
    cout << "--------------------------------------------------" << endl;

    return 0;
}