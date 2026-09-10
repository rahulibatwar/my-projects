#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);

    cout << "Top: " << myStack.top() << " (Expected: 2)" << endl;
    cout << "Pop: " << myStack.pop() << " (Expected: 2)" << endl;
    cout << boolalpha;
    cout << "Is Empty: " << myStack.empty() << " (Expected: false)" << endl;

    return 0;
}