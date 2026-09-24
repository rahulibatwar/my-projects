#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMax = 0, maxSum = nums[0];
        int currMin = 0, minSum = nums[0];

        for (int x : nums) {
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            totalSum += x;
        }

        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, -2, 3, -2};
    cout << "Example 1: " << sol.maxSubarraySumCircular(nums1) << " (Expected: 3)" << endl;

    vector<int> nums2 = {5, -3, 5};
    cout << "Example 2: " << sol.maxSubarraySumCircular(nums2) << " (Expected: 10)" << endl;

    vector<int> nums3 = {-3, -2, -3};
    cout << "Example 3: " << sol.maxSubarraySumCircular(nums3) << " (Expected: -2)" << endl;

    return 0;
}