#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charMap(256, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            charMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabcbb";
    cout << "Test Case 1 Output: " << sol.lengthOfLongestSubstring(s1) << " (Expected: 3)" << endl;

    string s2 = "bbbbb";
    cout << "Test Case 2 Output: " << sol.lengthOfLongestSubstring(s2) << " (Expected: 1)" << endl;

    string s3 = "pwwkew";
    cout << "Test Case 3 Output: " << sol.lengthOfLongestSubstring(s3) << " (Expected: 3)" << endl;

    return 0;
}