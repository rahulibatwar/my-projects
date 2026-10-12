#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    cout << "Example 1: ";
    printVector(nums1); // Expected: [ 1 3 2 ]

    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    cout << "Example 2: ";
    printVector(nums2); // Expected: [ 1 2 3 ]

    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    cout << "Example 3: ";
    printVector(nums3); // Expected: [ 1 5 1 ]

    return 0;
}