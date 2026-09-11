#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && m[s[i]] < m[s[i + 1]]) {
                ans -= m[s[i]];
            } else {
                ans += m[s[i]];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << "III: " << sol.romanToInt("III") << " (Expected: 3)" << endl;
    cout << "LVIII: " << sol.romanToInt("LVIII") << " (Expected: 58)" << endl;
    cout << "MCMXCIV: " << sol.romanToInt("MCMXCIV") << " (Expected: 1994)" << endl;

    return 0;
}