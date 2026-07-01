#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to find minimum edit distance using Top-Down DP (Memoization)
int editDistanceMemoized(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
    // Base Case 1: Agar s1 empty hai, toh saare characters s2 ke insert karne padenge
    if (m == 0) return n;

    // Base Case 2: Agar s2 empty hai, toh saare characters s1 ke delete karne padenge
    if (n == 0) return m;

    // Agar ye subproblem pehle se calculate ho chuki hai, toh purana answer return karo
    if (dp[m][n] != -1) return dp[m][n];

    // Agar last characters match kar rahe hain, toh koi cost nahi lagega
    if (s1[m - 1] == s2[n - 1]) {
        dp[m][n] = editDistanceMemoized(s1, s2, m - 1, n - 1, dp);
        return dp[m][n];
    }

    // Agar characters mismatch hain, toh 3 choices ka min nikalenge
    int insert_op  = editDistanceMemoized(s1, s2, m, n - 1, dp);     // Insert
    int delete_op  = editDistanceMemoized(s1, s2, m - 1, n, dp);     // Delete
    int replace_op = editDistanceMemoized(s1, s2, m - 1, n - 1, dp); // Replace

    // Teeno operations mein se jo sabse minimum cost dega, use save karenge (+1 cost for current op)
    dp[m][n] = 1 + min({insert_op, delete_op, replace_op});
    return dp[m][n];
}

int main() {
    cout << "--- DSA Masterclass: Edit Distance Problem using DP ---" << endl << endl;

    string s1 = "geek";
    string s2 = "gesek";

    int m = s1.length();
    int n = s2.length();

    // 2D DP array initialized with -1 of size (m + 1) x (n + 1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int result = editDistanceMemoized(s1, s2, m, n, dp);

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Minimum operations required to convert: " << result << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}