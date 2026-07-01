#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to find minimum attempts in worst case using Tabulation (Bottom-Up)
int eggDrop(int eggs, int floors) {
    // 2D DP Table: Row represent karegi eggs aur Column represent karega floors
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    // Base Case 1: Agar 1 floor hai toh 1 attempt, 0 floor hai toh 0 attempt
    for (int i = 1; i <= eggs; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    // Base Case 2: Agar sirf 1 egg hai, toh 'f' floors ke liye 'f' attempts lagenge hamesha
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }

    // Table ko fill karte hain standard DP transition se
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;

            // Har ek floor 'x' par drop karke check karo
            for (int x = 1; x <= j; x++) {
                // Break hone par: dp[i-1][x-1]
                // Na break hone par: dp[i][j-x]
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                
                // Hamein un worst-cases ka minimum chahiye
                dp[i][j] = min(dp[i][j], res);
            }
        }
    }

    // Final answer return karein
    return dp[eggs][floors];
}

int main() {
    cout << "--- DSA Masterclass: Egg Dropping Puzzle using DP ---" << endl << endl;

    int eggs = 2;
    int floors = 10;

    cout << "Number of Eggs: " << eggs << endl;
    cout << "Number of Floors: " << floors << endl;

    int min_attempts = eggDrop(eggs, floors);

    cout << "Minimum attempts needed in worst case: " << min_attempts << endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}