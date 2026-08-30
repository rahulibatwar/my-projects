#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    string s1 = "aa", p1 = "a";
    cout << "Test Case 1 Output: " << (sol.isMatch(s1, p1) ? "true" : "false") << " (Expected: false)" << endl;

    string s2 = "aa", p2 = "a*";
    cout << "Test Case 2 Output: " << (sol.isMatch(s2, p2) ? "true" : "false") << " (Expected: true)" << endl;

    string s3 = "ab", p3 = ".*";
    cout << "Test Case 3 Output: " << (sol.isMatch(s3, p3) ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}