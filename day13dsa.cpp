#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int total_sum = 0;
    int max_sum = INT_MIN, curr_max = 0;
    int min_sum = INT_MAX, curr_min = 0;

    for (int val : nums) {
        total_sum += val;

        // Kadane's for Maximum Sum
        curr_max += val;
        max_sum = max(max_sum, curr_max);
        if (curr_max < 0) curr_max = 0;

        // Kadane's for Minimum Sum
        curr_min += val;
        min_sum = min(min_sum, curr_min);
        if (curr_min > 0) curr_min = 0;
    }

    // Edge Case: If all numbers are negative, max_sum will be negative
    if (max_sum < 0) return max_sum;

    return max(max_sum, total_sum - min_sum);
}

int main() {
    vector<int> nums = {5, -3, 5};
    cout << "Maximum Circular Subarray Sum: " << maxSubarraySumCircular(nums) << endl; // Output: 10 ([5] + [5])
    return 0;
}