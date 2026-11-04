#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
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

    // Example 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    sol.merge(nums1, 3, nums2, 3);
    cout << "Example 1 Output: ";
    printVector(nums1); // Expected: [ 1 2 2 3 5 6 ]

    // Example 2
    vector<int> nums3 = {1};
    vector<int> nums4 = {};
    sol.merge(nums3, 1, nums4, 0);
    cout << "Example 2 Output: ";
    printVector(nums3); // Expected: [ 1 ]

    // Example 3
    vector<int> nums5 = {0};
    vector<int> nums6 = {1};
    sol.merge(nums5, 0, nums6, 1);
    cout << "Example 3 Output: ";
    printVector(nums5); // Expected: [ 1 ]

    return 0;
}