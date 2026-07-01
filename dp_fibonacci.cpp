#include <iostream>
#include <vector>
using namespace std;

// Top-Down DP approach (Recursion + Memoization)
int fibonacciDP(int n, vector<int>& dp) {
    // Base cases
    if (n <= 1) return n;

    // Agar answer pehle se calculated hai, toh direct return karo
    if (dp[n] != -1) {
        return dp[n];
    }

    // Answer calculate karke array mein store (save) karo
    dp[n] = fibonacciDP(n - 1, dp) + fibonacciDP(n - 2, dp);
    return dp[n];
}

int main() {
    cout << "--- DSA Masterclass: Fibonacci Series using DP ---" << endl << endl;

    int n = 6; // Hum 6th Fibonacci number nikalenge (0, 1, 1, 2, 3, 5, 8...)
    
    // DP array ko -1 se initialize karte hain (matlab abhi tak kuch calculate nahi hua)
    vector<int> dp(n + 1, -1);

    int result = fibonacciDP(n, dp);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    cout << "---------------------------------------------------" << endl;

    return 0;
}