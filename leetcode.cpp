#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = matrix[mid / n][mid % n];

            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };[cite: 28]

    cout << boolalpha;
    cout << "Example 1 (target = 3): " << sol.searchMatrix(matrix, 3) << " (Expected: true)\n";[cite: 28]
    cout << "Example 2 (target = 13): " << sol.searchMatrix(matrix, 13) << " (Expected: false)\n";

    return 0;
}