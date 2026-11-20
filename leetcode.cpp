#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        int prev2 = 1;
        int prev1 = 1;

        for (int i = 1; i < n; i++) {
            int current = 0;

            if (s[i] != '0') {
                current += prev1;
            }

            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            if (current == 0) {
                return 0;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (\"12\"): " << sol.numDecodings("12") << " (Expected: 2)\n";[cite: 24]
    cout << "Example 2 (\"226\"): " << sol.numDecodings("226") << " (Expected: 3)\n";
    cout << "Example 3 (\"06\"): " << sol.numDecodings("06") << " (Expected: 0)\n";[cite: 24]
    cout << "Test 4 (\"11106\"): " << sol.numDecodings("11106") << " (Expected: 2)\n";[cite: 24]

    return 0;
}