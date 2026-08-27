#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimized Sliding Window for non-negative integers
int longestSubarrayWithSumK(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int curr_sum = 0, max_len = 0;
    int n = nums.size();

    while (right < n) {
        curr_sum += nums[right];

        // Shrink window if sum exceeds k
        while (left <= right && curr_sum > k) {
            curr_sum -= nums[left];
            left++;
        }

        // Check if target sum is reached
        if (curr_sum == k) {
            max_len = max(max_len, right - left + 1);
        }
        right++;
    }
    return max_len;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << "Longest Subarray Length: " << longestSubarrayWithSumK(nums, k) << endl; // Output: 4 ([5, 2, 7, 1])
    return 0;
}