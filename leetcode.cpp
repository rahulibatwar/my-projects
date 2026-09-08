#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};

    cout << "Target 5 Index: " << sol.searchInsert(nums, 5) << " (Expected: 2)" << endl;
    cout << "Target 2 Index: " << sol.searchInsert(nums, 2) << " (Expected: 1)" << endl;
    cout << "Target 7 Index: " << sol.searchInsert(nums, 7) << " (Expected: 4)" << endl;

    return 0;
}