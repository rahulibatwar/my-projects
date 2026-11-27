#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int k = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

void printPrefix(const vector<int>& nums, int k) {
    cout << "k = " << k << ", nums = [ ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << (i + 1 < k ? ", " : " ");
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Example 1 -> ";
    printPrefix(nums1, k1); // Expected: k = 5, nums = [ 1, 1, 2, 2, 3 ]

    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Example 2 -> ";
    printPrefix(nums2, k2); // Expected: k = 7, nums = [ 0, 0, 1, 1, 2, 3, 3 ]

    return 0;
}