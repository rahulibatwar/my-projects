#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int max_sum = INT_MIN;
    int current_sum = 0;

    for (int val : nums) {
        current_sum += val;
        max_sum = max(max_sum, current_sum);

        // Reset if sum becomes negative
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, -4, 8, -9, 1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubarraySum(nums) << endl; // Output: 6
    return 0;
}