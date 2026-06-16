#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to find minimum coins needed using Bottom-Up DP
int minCoinsNeeded(const vector<int>& coins, int amount) {
    // dp[i] store karega ki amount 'i' banane ke liye kitne min coins chahiye
    // Size amount + 1 hoga, aur shuruat me sabko ek bade number (amount + 1) se fill karenge
    vector<int> dp(amount + 1, amount + 1);

    // Base Case: 0 amount banane ke liye 0 coins chahiye
    dp[0] = 0;

    // Har ek intermediate amount ke liye check karte hain
    for (int i = 1; i <= amount; i++) {
        // Har ek coin ko check karo ki kya use intermediate amount me include kar sakte hain
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Agar dp[amount] abhi bhi update nahi hua, matlab wo amount banana impossible hai
    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    cout << "--- DSA Masterclass: Coin Change Problem (Minimum Coins) ---" << endl << endl;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Available Coins: ";
    for (int c : coins) cout << c << " ";
    cout << endl << "Target Amount: RS " << amount << endl;

    int result = minCoinsNeeded(coins, amount);

    if (result != -1) {
        cout << "Minimum coins required to make change: " << result << endl;
    } else {
        cout << "It's impossible to make change for the given amount." << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    return 0;
}