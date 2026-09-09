#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    cout << boolalpha; // 1/0 की जगह true/false प्रिंट करने के लिए
    cout << "Search 0: " << sol.search(nums1, 0) << " (Expected: true)" << endl;
    cout << "Search 3: " << sol.search(nums1, 3) << " (Expected: false)" << endl;

    return 0;
}