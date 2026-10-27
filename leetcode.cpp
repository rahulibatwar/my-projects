#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[ ";
    for (const auto& iv : intervals) {
        cout << "[" << iv[0] << ", " << iv[1] << "] ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Example 1 Output: ";
    printIntervals(sol.merge(intervals1)); // Expected: [ [1, 6] [8, 10] [15, 18] ]

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    cout << "Example 2 Output: ";
    printIntervals(sol.merge(intervals2)); // Expected: [ [1, 5] ]

    return 0;
}