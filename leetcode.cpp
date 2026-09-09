#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Min Element: " << sol.findMin(nums1) << " (Expected: 1)" << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Min Element: " << sol.findMin(nums2) << " (Expected: 0)" << endl;

    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Min Element: " << sol.findMin(nums3) << " (Expected: 11)" << endl;

    return 0;
}