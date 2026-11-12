#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Example 1 Output: " << sol.minPathSum(grid1) << " (Expected: 7)\n";

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Example 2 Output: " << sol.minPathSum(grid2) << " (Expected: 12)\n";

    return 0;
}