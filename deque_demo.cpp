#include <iostream>
#include <deque> // C++ STL Deque Library
using namespace std;

int main() {
    cout << "--- DSA Masterclass: Double-Ended Queue (Deque) ---" << endl << endl;

    // Deque ka object banaya
    deque<int> dq;

    // 1. Piche se elements insert kiye
    dq.push_back(20);
    dq.push_back(30);

    // 2. Aage se element insert kiya
    dq.push_front(10); // Ab sequence hona chahiye: 10, 20, 30

    cout << "Front element: " << dq.front() << endl; // 10
    cout << "Back element: " << dq.back() << endl;   // 30
    cout << "--------------------------------------------" << endl;

    // 3. Piche se ek element delete karke dekhte hain
    dq.pop_back(); // 30 nikal jayega
    cout << "New Back element after pop_back: " << dq.back() << endl; // 20

    // 4. Aage se ek element delete karte hain
    dq.pop_front(); // 10 nikal jayega
    cout << "New Front element after pop_front: " << dq.front() << endl; // 20

    return 0;
}