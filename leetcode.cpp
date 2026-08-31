#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && m[s[i]] < m[s[i + 1]]) {
                total -= m[s[i]];
            } else {
                total += m[s[i]];
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    string s1 = "III";
    cout << "Test Case 1 Output: " << sol.romanToInt(s1) << " (Expected: 3)" << endl;

    string s2 = "LVIII";
    cout << "Test Case 2 Output: " << sol.romanToInt(s2) << " (Expected: 58)" << endl;

    string s3 = "MCMXCIV";
    cout << "Test Case 3 Output: " << sol.romanToInt(s3) << " (Expected: 1994)" << endl;

    return 0;
}