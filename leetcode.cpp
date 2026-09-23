#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << boolalpha;
    cout << "Example 1: " << sol.canJump(nums1) << " (Expected: true)" << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Example 2: " << sol.canJump(nums2) << " (Expected: false)" << endl;

    return 0;
}