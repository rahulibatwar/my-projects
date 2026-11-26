#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        int need = k - current.size();
        for (int i = start; i <= n - need + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};

void printCombinations(const vector<vector<int>>& res) {
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

    cout << "Example 1 (n = 4, k = 2): ";
    printCombinations(sol.combine(4, 2)); // Expected: [ [1,2], [1,3], [1,4], [2,3], [2,4], [3,4] ][cite: 28]

    cout << "Example 2 (n = 1, k = 1): ";
    printCombinations(sol.combine(1, 1)); // Expected: [ [1] ][cite: 28]

    return 0;
}