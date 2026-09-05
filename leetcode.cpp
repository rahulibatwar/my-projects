#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int insertIndex = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }

        return insertIndex;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [1, 1, 2] -> k = 2, nums = [1, 2]
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Test Case 1 (k = " << k1 << "): ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << endl;

    // Test Case 2: [0,0,1,1,1,2,2,3,3,4] -> k = 5, nums = [0, 1, 2, 3, 4]
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Test Case 2 (k = " << k2 << "): ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << endl;

    return 0;
}