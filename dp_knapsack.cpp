#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming (Tabulation)
int solveKnapsack(int W, vector<int>& weights, vector<int>& profits, int n) {
    // Creating a 2D DP Table initialized with 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If the current item's weight is less than or equal to the remaining capacity
            if (weights[i - 1] <= w) {
                // Max of: Including the item OR Excluding the item
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Excluding the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Return the maximum optimized profit
}

int main() {
    cout << "--- DSA Masterclass: 0/1 Knapsack (Dynamic Programming) ---" << endl << endl;

    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // Total capacity of the bag
    int n = profits.size();

    cout << "Knapsack Capacity: " << W << " kg" << endl;
    cout << "Available Items [Profit, Weight]:" << endl;
    for (int i = 0; i < n; i++) {
        cout << " -> Item " << i + 1 << ": [" << profits[i] << " Rs, " << weights[i] << " kg]" << endl;
    }
    cout << endl;

    int maxProfit = solveKnapsack(W, weights, profits, n);

    cout << "--------------------------------------------------------" << endl;
    cout << "Maximum Optimized Profit obtained: Rs " << maxProfit << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}