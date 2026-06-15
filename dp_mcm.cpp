#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Matrix Chain Multiplication using Top-Down Memoization
int matrixChainMemoized(const vector<int>& p, int i, int j, vector<vector<int>>& dp) {
    // Base Case: Agar sirf ek hi matrix bachi hai, toh multiplication cost 0 hoga
    if (i == j) return 0;

    // Agar state pehle se calculated hai, toh return karein
    if (dp[i][j] != -1) return dp[i][j];

    int min_cost = INT_MAX;

    // Chain ko alag-alag position 'k' par tod kar check karte hain (Partitioning)
    for (int k = i; k < j; k++) {
        int cost = matrixChainMemoized(p, i, k, dp) + 
                   matrixChainMemoized(p, k + 1, j, dp) + 
                   p[i - 1] * p[k] * p[j];

        min_cost = min(min_cost, cost);
    }

    // Result ko matrix mein store karte hain
    dp[i][j] = min_cost;
    return dp[i][j];
}

int main() {
    cout << "--- DSA Masterclass: Matrix Chain Multiplication (MCM) ---" << endl << endl;

    // Dimensions array format: Matrix A1 is 10x20, A2 is 20x30, A3 is 30x40
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();

    // 2D DP array size n x n, initialized with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Array size n hai, toh total matrices (n-1) yaani 3 hain. Chain 1 se 3 tak chalegi.
    int min_operations = matrixChainMemoized(arr, 1, n - 1, dp);

    cout << "Minimum number of scalar multiplications needed: " << min_operations << endl;
    cout << "-----------------------------------------------------------" << endl;

    return 0;
}