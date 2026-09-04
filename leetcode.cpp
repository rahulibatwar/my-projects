#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();
        string ans = "";

        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            ans += first[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Cases
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Test Case 1 Output: \"" << sol.longestCommonPrefix(strs1) << "\" (Expected: \"fl\")" << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Test Case 2 Output: \"" << sol.longestCommonPrefix(strs2) << "\" (Expected: \"\")" << endl;

    return 0;
}