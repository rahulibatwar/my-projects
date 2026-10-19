#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            current.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtrack(nums, used, current, result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = sol.permuteUnique(nums1);

    cout << "Permutations for [1, 1, 2]:\n";
    for (const auto& p : res1) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}