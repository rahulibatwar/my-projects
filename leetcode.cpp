#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Example 1: " << sol.trap(height1) << " (Expected: 6)" << endl;

    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Example 2: " << sol.trap(height2) << " (Expected: 9)" << endl;

    return 0;
}