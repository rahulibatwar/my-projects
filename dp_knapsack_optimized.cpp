#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack using highly optimized 1D DP Array
int solveKnapsackOptimized(int W, vector<int>& weights, vector<int>& profits, int n) {
    // 1D DP Table initialized with 0 (Drastic Space Reduction from 2D to 1D)
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Traverse the capacity array backwards to avoid overwriting current row states
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], profits[i] + dp[w - weights[i]]);
        }
    }

    return dp[W]; // Highly space-optimized maximum profit
}

int main() {
    cout << "--- DSA Masterclass: 1D Space Optimized 0/1 Knapsack (DP) ---" << endl << endl;

    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; 
    int n = profits.size();

    cout << "Knapsack Capacity: " << W << " kg" << endl;
    cout << "Items configuration is loaded successfully." << endl << endl;

    int maxProfit = solveKnapsackOptimized(W, weights, profits, n);

    cout << "--------------------------------------------------------" << endl;
    cout << "Maximum Space Optimized Profit: Rs " << maxProfit << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}