#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (a = \"11\", b = \"1\"): " 
         << sol.addBinary("11", "1") << " (Expected: 100)\n"; //[cite: 23]

    cout << "Example 2 (a = \"1010\", b = \"1011\"): " 
         << sol.addBinary("1010", "1011") << " (Expected: 10101)\n"; //[cite: 23]

    return 0;
}