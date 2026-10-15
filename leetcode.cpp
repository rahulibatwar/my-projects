#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            } else if (starIdx != -1) {
                pIdx = starIdx + 1;
                sTmpIdx++;
                sIdx = sTmpIdx;
            } else {
                return false;
            }
        }

        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << "Example 1: " << sol.isMatch("aa", "a") << " (Expected: false)" << endl;
    cout << "Example 2: " << sol.isMatch("aa", "*") << " (Expected: true)" << endl;
    cout << "Example 3: " << sol.isMatch("cb", "?a") << " (Expected: false)" << endl;

    return 0;
}