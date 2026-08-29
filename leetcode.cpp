#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0; // Overflow detect karne ke liye

        // Step 1: Shuruat ke khali spaces ko skip karo
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Sign check karo ('+' ya '-')
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Digits ko padho aur number banao
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            result = result * 10 + digit;

            // Step 4: 32-bit Integer Limit Overflow Check (Clamping)
            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * result;
    }
};

int main() {
    Solution sol;

    // Test Cases
    string s1 = "42";
    cout << "Test Case 1 Output: " << sol.myAtoi(s1) << " (Expected: 42)" << endl;

    string s2 = " -042";
    cout << "Test Case 2 Output: " << sol.myAtoi(s2) << " (Expected: -42)" << endl;

    string s3 = "1337c0d3";
    cout << "Test Case 3 Output: " << sol.myAtoi(s3) << " (Expected: 1337)" << endl;

    string s4 = "0-1";
    cout << "Test Case 4 Output: " << sol.myAtoi(s4) << " (Expected: 0)" << endl;

    string s5 = "91283472332"; // Overflow Case
    cout << "Test Case 5 Output: " << sol.myAtoi(s5) << " (Expected: 2147483647)" << endl;

    return 0;
}