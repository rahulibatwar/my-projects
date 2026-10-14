#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 0};
    cout << "Example 1: " << sol.firstMissingPositive(nums1) << " (Expected: 3)" << endl;

    vector<int> nums2 = {3, 4, -1, 1};
    cout << "Example 2: " << sol.firstMissingPositive(nums2) << " (Expected: 2)" << endl;

    vector<int> nums3 = {7, 8, 9, 11, 12};
    cout << "Example 3: " << sol.firstMissingPositive(nums3) << " (Expected: 1)" << endl;

    return 0;
}