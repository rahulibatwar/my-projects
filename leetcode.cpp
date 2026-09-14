#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans = "";
        int idx = 0;
        while (idx < result.size() && result[idx] == 0) {
            idx++;
        }

        while (idx < result.size()) {
            ans.push_back(result[idx] + '0');
            idx++;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << "2 * 3 = " << sol.multiply("2", "3") << " (Expected: 6)" << endl;
    cout << "123 * 456 = " << sol.multiply("123", "456") << " (Expected: 56088)" << endl;

    return 0;
}