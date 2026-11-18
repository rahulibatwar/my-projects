#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<int> dp(n + 1, 0);

        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            int prevDiag = dp[0];
            dp[0] = i;

            for (int j = 1; j <= n; j++) {
                int temp = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prevDiag;
                } else {
                    dp[j] = 1 + min({dp[j], dp[j - 1], prevDiag});
                }

                prevDiag = temp;
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (\"horse\", \"ros\"): " 
         << sol.minDistance("horse", "ros") << " (Expected: 3)\n";[cite: 22]

    cout << "Example 2 (\"intention\", \"execution\"): " 
         << sol.minDistance("intention", "execution") << " (Expected: 5)\n";[cite: 22]

    return 0;
}