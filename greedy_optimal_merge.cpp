#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to calculate the minimum computation cost for merging files
int getMinMergeCost(vector<int>& files) {
    // Create a min-heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all file sizes into the min-heap
    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    // Iterate until only one major merged file is left in the heap
    while (minHeap.size() > 1) {
        // Extract the two smallest files
        int first_smallest = minHeap.top();
        minHeap.pop();

        int second_smallest = minHeap.top();
        minHeap.pop();

        // Cost to merge these two files
        int currentMergeCost = first_smallest + second_smallest;
        totalCost += currentMergeCost;

        // Push the merged file back into the min-heap
        minHeap.push(currentMergeCost);
    }

    return totalCost;
}

int main() {
    cout << "--- DSA Masterclass: Optimal Merge Pattern (Greedy) ---" << endl << endl;

    // Sizes of different sorted files
    vector<int> files = {5, 10, 20, 30, 30};

    cout << "Sizes of files to be merged: ";
    for (int size : files) {
        cout << size << "KB ";
    }
    cout << endl << endl;

    // Running the optimal merge engine
    int minCost = getMinMergeCost(files);

    cout << "--------------------------------------------------------" << endl;
    cout << "Minimum Optimal Computation Cost: " << minCost << " operations" << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}