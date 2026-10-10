#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums, result);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> perms = sol.permute(nums);

    cout << "Total Permutations: " << perms.size() << " (Expected: 6)\n";
    for (const auto& p : perms) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}