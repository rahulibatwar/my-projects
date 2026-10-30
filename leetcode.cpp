#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        int total = n * n;

        while (num <= total) {
            for (int col = left; col <= right && num <= total; col++) {
                matrix[top][col] = num++;
            }
            top++;

            for (int row = top; row <= bottom && num <= total; row++) {
                matrix[row][right] = num++;
            }
            right--;

            for (int col = right; col >= left && num <= total; col--) {
                matrix[bottom][col] = num++;
            }
            bottom--;

            for (int row = bottom; row >= top && num <= total; row--) {
                matrix[row][left] = num++;
            }
            left++;
        }

        return matrix;
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        cout << "[ ";
        for (int val : row) cout << val << " ";
        cout << "]\n";
    }
}

int main() {
    Solution sol;

    cout << "Example 1 (n = 3):\n";
    printMatrix(sol.generateMatrix(3));

    cout << "\nExample 2 (n = 1):\n";
    printMatrix(sol.generateMatrix(1));

    return 0;
}