#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LCS function using Top-Down Memoization DP
int lcsDP(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
    // Base Case: Agar koi bhi ek string empty ho jaye, toh common sequence 0 hogi
    if (m == 0 || n == 0) return 0;

    // Agar ye state pehle se calculate ho chuki hai, toh return karein
    if (dp[m][n] != -1) return dp[m][n];

    // Case 1: Agar characters match kar gaye
    if (s1[m - 1] == s2[n - 1]) {
        dp[m][n] = 1 + lcsDP(s1, s2, m - 1, n - 1, dp);
        return dp[m][n];
    }
    // Case 2: Agar mismatch hua, toh dono directions ka max nikalenge
    else {
        dp[m][n] = max(lcsDP(s1, s2, m - 1, n, dp), lcsDP(s1, s2, m, n - 1, dp));
        return dp[m][n];
    }
}

int main() {
    cout << "--- DSA Masterclass: Longest Common Subsequence (LCS) using DP ---" << endl << endl;

    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    
    int m = s1.length();
    int n = s2.length();

    // (m+1) x (n+1) ka 2D DP Vector banayein aur sabko -1 se fill karein
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int lcs_length = lcsDP(s1, s2, m, n, dp);

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Length of Longest Common Subsequence is: " << lcs_length << endl;
    cout << "------------------------------------------------------------------" << endl;

    return 0;
}