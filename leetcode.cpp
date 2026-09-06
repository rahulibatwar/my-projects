#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();

        if (n > h) return -1;

        for (int i = 0; i <= h - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1: haystack = "sadbutsad", needle = "sad" -> 0
    string h1 = "sadbutsad", n1 = "sad";
    cout << "Test Case 1 Output: " << sol.strStr(h1, n1) << " (Expected: 0)" << endl;

    // Test Case 2: haystack = "leetcode", needle = "leeto" -> -1
    string h2 = "leetcode", n2 = "leeto";
    cout << "Test Case 2 Output: " << sol.strStr(h2, n2) << " (Expected: -1)" << endl;

    return 0;
}