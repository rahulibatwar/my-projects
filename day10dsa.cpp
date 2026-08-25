#include <iostream>
#include <vector>
#include <climits>
#include <utility> // pair ke liye

using namespace std;

// Utility function jo maximum aur minimum subarray sum dono return karta hai
pair<int, int> findMaxAndMinSubarraySum(const vector<int>& nums) {
    // Variable initializations
    int max_sum = INT_MIN, current_max = 0;
    int min_sum = INT_MAX, current_min = 0;

    for (int val : nums) {
        // 1. Maximum Subarray Sum Logic (Kadane's Algorithm)
        current_max += val;
        max_sum = max(max_sum, current_max);
        if (current_max < 0) {
            current_max = 0;
        }

        // 2. Minimum Subarray Sum Logic
        current_min += val;
        min_sum = min(min_sum, current_min);
        if (current_min > 0) {
            current_min = 0;
        }
    }

    // pair<Max, Min> return kar rahe hain
    return {max_sum, min_sum};
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Function call
    pair<int, int> result = findMaxAndMinSubarraySum(nums);

    cout << "Maximum Subarray Sum: " << result.first << endl;  // Output: 6
    cout << "Minimum Subarray Sum: " << result.second << endl; // Output: -6

    return 0;
}