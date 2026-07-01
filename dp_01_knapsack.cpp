#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0/1 Knapsack function using Memoization (Top-Down DP)
int knapsackDP(int W, const vector<int>& wt, const vector<int>& val, int n, vector<vector<int>>& dp) {
    // Base Case: Agar bag ki capacity khatam ho jaye ya items khatam ho jayein
    if (n == 0 || W == 0) return 0;

    // Agar ye subproblem hum pehle hi solve kar chuke hain, toh purana answer return karo
    if (dp[n][W] != -1) return dp[n][W];

    // Choice 1: Agar current item ka weight bag ki total capacity se zyada hai
    // Toh hum is item ko bag mein nahi daal sakte (Skip current item)
    if (wt[n - 1] > W) {
        dp[n][W] = knapsackDP(W, wt, val, n - 1, dp);
        return dp[n][W];
    }
    // Choice 2: Hum item ko le bhi sakte hain aur chhod bhi sakte hain (Max nikalenge)
    else {
        int include_item = val[n - 1] + knapsackDP(W - wt[n - 1], wt, val, n - 1, dp);
        int exclude_item = knapsackDP(W, wt, val, n - 1, dp);
        
        // Dono choices mein se jahan zyada fayda/profit hoga use select karenge
        dp[n][W] = max(include_item, exclude_item);
        return dp[n][W];
    }
}

int main() {
    cout << "--- DSA Masterclass: 0/1 Knapsack Problem using DP ---" << endl << endl;

    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50; // Bag ki maximum weight capacity
    int n = profit.size();

    // 2D DP array banayein size (n + 1) x (W + 1) aur sabko -1 se fill kar dein
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int max_profit = knapsackDP(W, weight, profit, n, dp);

    cout << "Maximum profit we can earn in 0/1 Knapsack: RS " << max_profit << endl;
    cout << "------------------------------------------------------" << endl;

    return 0;
}