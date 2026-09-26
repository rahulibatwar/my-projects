#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > K) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* kthLargest = new KthLargest(3, nums);

    cout << "add(3): " << kthLargest->add(3) << " (Expected: 4)" << endl;
    cout << "add(5): " << kthLargest->add(5) << " (Expected: 5)" << endl;
    cout << "add(10): " << kthLargest->add(10) << " (Expected: 5)" << endl;
    cout << "add(9): " << kthLargest->add(9) << " (Expected: 8)" << endl;
    cout << "add(4): " << kthLargest->add(4) << " (Expected: 8)" << endl;

    delete kthLargest;
    return 0;
}