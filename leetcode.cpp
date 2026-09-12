#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(const string& digits, int index, string current, 
                   vector<string>& result, const vector<string>& keypad) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = keypad[digits[index] - '0'];
        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch, result, keypad);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        backtrack(digits, 0, "", result, keypad);
        return result;
    }
};

int main() {
    Solution sol;

    vector<string> ans = sol.letterCombinations("23");

    cout << "Combinations for '23':" << endl;
    for (const string& s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}