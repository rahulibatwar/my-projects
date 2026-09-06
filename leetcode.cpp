#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    // Test Case 1: nums = [3,2,2,3], val = 3 -> k = 2, nums = [2,2]
    vector<int> nums1 = {3, 2, 2, 3};
    int k1 = sol.removeElement(nums1, 3);
    cout << "Test Case 1 (k = " << k1 << "): ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << endl;

    // Test Case 2: nums = [0,1,2,2,3,0,4,2], val = 2 -> k = 5
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = sol.removeElement(nums2, 2);
    cout << "Test Case 2 (k = " << k2 << "): ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << endl;

    return 0;
}