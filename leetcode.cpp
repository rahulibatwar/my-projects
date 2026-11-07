#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> mapT(128, 0);
        for (char c : t) {
            mapT[c]++;
        }

        int left = 0;
        int right = 0;
        int required = t.length();
        int minLen = INT_MAX;
        int startIndex = 0;

        while (right < s.length()) {
            if (mapT[s[right]] > 0) {
                required--;
            }
            mapT[s[right]]--;
            right++;

            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    startIndex = left;
                }

                mapT[s[left]]++;
                if (mapT[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    Solution sol;

    cout << "Example 1: \"" << sol.minWindow("ADOBECODEBANC", "ABC") << "\" (Expected: \"BANC\")\n";
    cout << "Example 2: \"" << sol.minWindow("a", "a") << "\" (Expected: \"a\")\n";
    cout << "Example 3: \"" << sol.minWindow("a", "aa") << "\" (Expected: \"\")\n";

    return 0;
}