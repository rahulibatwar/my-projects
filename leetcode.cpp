#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(int start, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};

void printSubsets(const vector<vector<int>>& res) {
    cout << "[ ";
    for (size_t i = 0; i < res.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << (j + 1 < res[i].size() ? "," : "");
        }
        cout << "]" << (i + 1 < res.size() ? ", " : " ");
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    cout << "Example 1 Output: ";
    printSubsets(sol.subsets(nums1));

    vector<int> nums2 = {0};
    cout << "Example 2 Output: ";
    printSubsets(sol.subsets(nums2));

    return 0;
}