#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Test Case 1 Output: " << sol.convert(s1, numRows1) << " (Expected: PAHNAPLSIIGYIR)" << endl;

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Test Case 2 Output: " << sol.convert(s2, numRows2) << " (Expected: PINALSIGYAHRPI)" << endl;

    return 0;
}