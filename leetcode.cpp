#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int n, int open, int close, string current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(n, open + 1, close, current + "(", result);
        }

        if (close < open) {
            backtrack(n, open, close + 1, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};

int main() {
    Solution sol;

    vector<string> ans = sol.generateParenthesis(3);

    cout << "Generated Parentheses for n = 3:" << endl;
    for (const string& s : ans) {
        cout << s << endl;
    }

    return 0;
}