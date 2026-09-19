#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int x : nums) total_sum += x;

        if (n <= 1) return false;

        int m = n / 2;
        bool possible = false;
        for (int k = 1; k <= m; k++) {
            if ((total_sum * k) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);

        for (int num : nums) {
            for (int k = m; k >= 1; k--) {
                for (int prev_sum : dp[k - 1]) {
                    dp[k].insert(prev_sum + num);
                }
            }
        }

        for (int k = 1; k <= m; k++) {
            if ((total_sum * k) % n == 0) {
                int target_sum = (total_sum * k) / n;
                if (dp[k].count(target_sum)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << boolalpha;
    cout << "Example 1: " << sol.splitArraySameAverage(nums1) << " (Expected: true)" << endl;

    vector<int> nums2 = {3, 1};
    cout << "Example 2: " << sol.splitArraySameAverage(nums2) << " (Expected: false)" << endl;

    return 0;
}