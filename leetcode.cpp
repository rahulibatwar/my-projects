#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalMoves = m + n - 2;
        int r = min(m - 1, n - 1);
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (totalMoves - r + i) / i;
        }

        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (m = 3, n = 7): " << sol.uniquePaths(3, 7) << " (Expected: 28)\n";
    cout << "Example 2 (m = 3, n = 2): " << sol.uniquePaths(3, 2) << " (Expected: 3)\n";
    cout << "Example 3 (m = 7, n = 3): " << sol.uniquePaths(7, 3) << " (Expected: 28)\n";
    cout << "Example 4 (m = 1, n = 1): " << sol.uniquePaths(1, 1) << " (Expected: 1)\n";

    return 0;
}