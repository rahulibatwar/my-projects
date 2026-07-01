#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find maximum profit using Bottom-Up DP
int maxProfitRodCutting(const vector<int>& price, int n) {
    // dp[i] store karega 'i' length ki rod se milne wala max profit
    vector<int> dp(n + 1, 0);

    // Bottom-Up manner mein har ek rod length ka max profit calculate karein
    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        // Rod ko alag-alag cut points par tod kar check karte hain
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    cout << "--- DSA Masterclass: Rod Cutting Problem using DP ---" << endl << endl;

    // Prices for length 1 to 8 respectively
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_length = 8;

    cout << "Prices for lengths 1 to 8: ";
    for (int p : price) cout << p << " ";
    cout << endl << "Total Rod Length: " << rod_length << " meters" << endl;

    int result = maxProfitRodCutting(price, rod_length);

    cout << "Maximum profit earned by cutting the rod: RS " << result << endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}