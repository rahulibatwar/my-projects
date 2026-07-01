#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to check if a word exists in our dictionary
bool dictionaryContains(const string& word, const vector<string>& dict) {
    return find(dict.begin(), dict.end(), word) != dict.end();
}

// Function to check if the string can be segmented using Bottom-Up DP
bool wordBreak(string s, const vector<string>& dict) {
    int n = s.size();
    if (n == 0) return true;

    // dp[i] true hoga agar s[0...i-1] valid words mein segment ho sake
    vector<bool> dp(n + 1, false);

    // Base Case: Empty string hamesha valid partition hoti hai
    dp[0] = true;

    // Outer loop substring ki length badhata jayega
    for (int i = 1; i <= n; i++) {
        // Inner loop check karega ki kya koi valid split point 'j' milta hai
        for (int j = 0; j < i; j++) {
            // Agar pehla part dp[j] valid hai, toh bacha hua part s[j...i-j] check karo
            if (dp[j] && dictionaryContains(s.substr(j, i - j), dict)) {
                dp[i] = true;
                break; // Ek valid split mil gaya, toh aage is length ke liye check karne ki zaroorat nahi
            }
        }
    }

    return dp[n];
}

int main() {
    cout << "--- DSA Masterclass: Word Break Problem using DP ---" << endl << endl;

    vector<string> dict = {"apple", "pen", "applepen", "google"};
    string s = "applepenapple";

    cout << "Dictionary: ";
    for (const string& w : dict) cout << "[" << w << "] ";
    cout << endl << "Input String: " << s << endl;

    if (wordBreak(s, dict)) {
        cout << "Result: YES, the string can be segmented into dictionary words!" << endl;
    } else {
        cout << "Result: NO, the string cannot be segmented." << endl;
    }
    cout << "----------------------------------------------------" << endl;

    return 0;
}