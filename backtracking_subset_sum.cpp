#include <iostream>
#include <vector>

using namespace std;

// Print the subset found
void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}" << endl;
}

// Backtracking utility function
void subsetSumUtil(const vector<int>& set, int target, vector<int>& currentSubset, int index, int currentSum) {
    // Base Case: If current sum matches the target
    if (currentSum == target) {
        printSubset(currentSubset);
        return;
    }

    // Explore further elements
    for (int i = index; i < set.size(); i++) {
        // Optimization step: Skip if adding this element exceeds the target
        if (currentSum + set[i] <= target) {
            
            // Include the current element
            currentSubset.push_back(set[i]);

            // Recur for remaining elements
            subsetSumUtil(set, target, currentSubset, i + 1, currentSum + set[i]);

            // BACKTRACK: Remove the element to explore other subsets
            currentSubset.pop_back();
        }
    }
}

int main() {
    cout << "--- DSA Masterclass: Subset Sum Problem (C++) ---" << endl << endl;

    vector<int> set = {10, 7, 5, 18, 12, 20};
    int target = 35;
    vector<int> currentSubset;

    cout << "Target Sum: " << target << endl;
    cout << "Subsets that sum up to " << target << " are:" << endl;
    cout << "------------------------------------------" << endl;
    
    subsetSumUtil(set, target, currentSubset, 0, 0);
    
    cout << "------------------------------------------" << endl;

    return 0;
}