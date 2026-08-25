#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void findMaxAndMinSubarraySum(const vector<int>& nums) {
    int max_sum = INT_MIN, curr_max = 0;
    int min_sum = INT_MAX, curr_min = 0;

    for (int val : nums) {
        // 1. Max Subarray Sum Logic
        curr_max += val;
        max_sum = max(max_sum, curr_max);
        if (curr_max < 0) curr_max = 0;

        // 2. Min Subarray Sum Logic
        curr_min += val;
        min_sum = min(min_sum, curr_min);
        if (curr_min > 0) curr_min = 0;
    }

    cout << "Maximum Subarray Sum: " << max_sum << endl;
    cout << "Minimum Subarray Sum: " << min_sum << endl;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    findMaxAndMinSubarraySum(nums);
    return 0;
}