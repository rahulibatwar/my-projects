#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Example 1: " << sol.search(nums1, 0) << " (Expected: 4)" << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Example 2: " << sol.search(nums2, 3) << " (Expected: -1)" << endl;

    vector<int> nums3 = {1};
    cout << "Example 3: " << sol.search(nums3, 0) << " (Expected: -1)" << endl;

    return 0;
}