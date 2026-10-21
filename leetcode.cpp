#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int start, int target, vector<int>& candidates, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    vector<vector<int>> res1 = sol.combinationSum2(candidates1, target1);

    cout << "Combinations for target = 8:\n";
    for (const auto& comb : res1) {
        cout << "[ ";
        for (int x : comb) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}