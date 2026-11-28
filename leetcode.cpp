#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Example 1 Output: " << sol.largestRectangleArea(heights1) << " (Expected: 10)\n";[cite: 21]

    vector<int> heights2 = {2, 4};
    cout << "Example 2 Output: " << sol.largestRectangleArea(heights2) << " (Expected: 4)\n";[cite: 21]

    return 0;
}