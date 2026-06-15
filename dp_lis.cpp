#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find length of Longest Increasing Subsequence using Bottom-Up DP
int lisBottomUp(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // DP array: Har single element khud mein length 1 ki subsequence hota hai
    vector<int> dp(n, 1);

    // Bottom-Up manner mein har state calculate karein
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Agar piche wala number chota hai, toh increasing state valid hai
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Pure DP array mein jo sabse maximum value hogi, wahi hamari answer hogi
    int max_lis = 0;
    for (int i = 0; i < n; i++) {
        max_lis = max(max_lis, dp[i]);
    }

    return max_lis;
}

int main() {
    cout << "--- DSA Masterclass: Longest Increasing Subsequence (LIS) ---" << endl << endl;

    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    
    cout << "Input Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int result = lisBottomUp(arr);

    cout << "Length of Longest Increasing Subsequence is: " << result << endl;
    cout << "--------------------------------------------------------------" << endl;

    return 0;
}