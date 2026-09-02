#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string result = "";
        for (const auto& [val, sym] : roman) {
            while (num >= val) {
                result += sym;
                num -= val;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Cases
    int num1 = 3749;
    cout << "Test Case 1 Output: " << sol.intToRoman(num1) << " (Expected: MMMDCCXLIX)" << endl;

    int num2 = 58;
    cout << "Test Case 2 Output: " << sol.intToRoman(num2) << " (Expected: LVIII)" << endl;

    int num3 = 1994;
    cout << "Test Case 3 Output: " << sol.intToRoman(num3) << " (Expected: MCMXCIV)" << endl;

    return 0;
}