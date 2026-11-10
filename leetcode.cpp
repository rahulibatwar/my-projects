#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }

        return maxRectangle;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> mat1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << "Example 1 Output: " << sol.maximalRectangle(mat1) << " (Expected: 6)\n"; //[cite: 21]

    vector<vector<char>> mat2 = {{'0'}};
    cout << "Example 2 Output: " << sol.maximalRectangle(mat2) << " (Expected: 0)\n"; //[cite: 21]

    vector<vector<char>> mat3 = {{'1'}};
    cout << "Example 3 Output: " << sol.maximalRectangle(mat3) << " (Expected: 1)\n"; //[cite: 21]

    return 0;
}