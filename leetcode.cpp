#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

void printVector(const vector<int>& nums) {
    cout << "[ ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Example 1 Output: ";
    printVector(nums1); // Expected: [ 0 0 1 1 2 2 ]

    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Example 2 Output: ";
    printVector(nums2); // Expected: [ 0 1 2 ]

    return 0;
}