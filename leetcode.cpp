#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // 
        unordered_set<int> s(nums.begin(), nums.end());
        
        
        int target = k;
        while (s.count(target)) {
            target += k; // Agla multiple
        }
        
        // 
        return target;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    cout << "Test Case 1 Output: " << sol.missingMultiple(nums1, k1) << " (Expected: 10)" << endl;

    // Test Case 2
    vector<int> nums2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    cout << "Test Case 2 Output: " << sol.missingMultiple(nums2, k2) << " (Expected: 5)" << endl;

    return 0;
}