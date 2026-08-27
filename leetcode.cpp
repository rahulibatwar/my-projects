#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(i, i);
            int len2 = expandAroundCenter(i, i + 1);
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;

    string s1 = "babad";
    cout << "Test Case 1 Output: " << sol.longestPalindrome(s1) << " (Expected: bab or aba)" << endl;

    string s2 = "cbbd";
    cout << "Test Case 2 Output: " << sol.longestPalindrome(s2) << " (Expected: bb)" << endl;

    return 0;
}