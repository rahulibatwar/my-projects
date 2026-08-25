#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubarraySum(vector<int>& nums) {
    int min_sum = INT_MAX;
    int current_sum = 0;

    for (int val : nums) {
        current_sum += val;
        min_sum = min(min_sum, current_sum);

        // Reset if sum becomes positive
        if (current_sum > 0) {
            current_sum = 0;
        }
    }
    return min_sum;
}

int main() {
    vector<int> nums = {3, -4, 2, -3, -1, 7};
    cout << "Minimum Subarray Sum: " << minSubarraySum(nums) << endl; // Output: -6
    return 0;
}