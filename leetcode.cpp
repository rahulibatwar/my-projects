#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                firstPos = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return firstPos;
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lastPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                lastPos = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return lastPos;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = findLast(nums, target);
        return {first, last};
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> res1 = sol.searchRange(nums1, 8);
    cout << "Example 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [3, 4])\n";

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> res2 = sol.searchRange(nums2, 6);
    cout << "Example 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [-1, -1])\n";

    vector<int> nums3 = {};
    vector<int> res3 = sol.searchRange(nums3, 0);
    cout << "Example 3: [" << res3[0] << ", " << res3[1] << "] (Expected: [-1, -1])\n";

    return 0;
}