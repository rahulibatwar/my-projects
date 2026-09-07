#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest_sum;
    }
};

int main() {
    Solution sol;

    // Example 1: [-1, 2, 1, -4], target = 1 -> Output: 2
    vector<int> nums1 = {-1, 2, 1, -4};
    cout << "Output 1: " << sol.threeSumClosest(nums1, 1) << " (Expected: 2)" << endl;

    // Example 2: [0, 0, 0], target = 1 -> Output: 0
    vector<int> nums2 = {0, 0, 0};
    cout << "Output 2: " << sol.threeSumClosest(nums2, 1) << " (Expected: 0)" << endl;

    return 0;
}