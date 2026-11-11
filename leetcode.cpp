#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenExp) {
                    digitAfterExp = true;
                }
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == '.') {
                if (seenDot || seenExp) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) {
                    return false;
                }
                seenExp = true;
                digitAfterExp = false;
            } else {
                return false;
            }
        }

        return seenDigit && digitAfterExp;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << "Example 1 (\"0\"): " << sol.isNumber("0") << " (Expected: true)\n"; //[cite: 22]
    cout << "Example 2 (\"e\"): " << sol.isNumber("e") << " (Expected: false)\n"; //[cite: 22]
    cout << "Example 3 (\".\"): " << sol.isNumber(".") << " (Expected: false)\n"; //[cite: 22]
    cout << "Test 4 (\"-123.456e789\"): " << sol.isNumber("-123.456e789") << " (Expected: true)\n"; //[cite: 22]
    cout << "Test 5 (\"99e2.5\"): " << sol.isNumber("99e2.5") << " (Expected: false)\n"; //[cite: 22]

    return 0;
}