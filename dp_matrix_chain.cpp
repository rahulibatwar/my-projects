#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum multiplication cost using DP Tabulation
int matrixChainOrder(vector<int>& p, int n) {
    // dp[i][j] stores the minimum number of scalar multiplications needed to compute the matrix M[i]..M[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX; // Initialize with infinity

            for (int k = i; k <= j - 1; k++) {
                // Cost = left cost + right cost + current multiplication cost
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    return dp[1][n - 1]; // Return the highly optimized minimum cost
}

int main() {
    cout << "--- DSA Masterclass: Matrix Chain Multiplication (DP) ---" << endl << endl;

    // Matrix dimensions array: Matrix sizes are 10x20, 20x30, 30x40
    vector<int> arr = {10, 20, 30, 40};
    int size = arr.size();

    cout << "Matrix Dimensions Sequence: ";
    for (int dim : arr) {
        cout << dim << " ";
    }
    cout << endl << endl;

    int minCost = matrixChainOrder(arr, size);

    cout << "--------------------------------------------------------" << endl;
    cout << "Minimum Optimized Multiplication Cost is: " << minCost << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}