#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<int> d1 = {1, 2, 3};
    vector<int> res1 = sol.plusOne(d1);
    cout << "Example 1 Output: ";
    printVector(res1); // Expected: [ 1 2 4 ]

    vector<int> d2 = {4, 3, 2, 1};
    vector<int> res2 = sol.plusOne(d2);
    cout << "Example 2 Output: ";
    printVector(res2); // Expected: [ 4 3 2 2 ]

    vector<int> d3 = {9};
    vector<int> res3 = sol.plusOne(d3);
    cout << "Example 3 Output: ";
    printVector(res3); // Expected: [ 1 0 ]

    vector<int> d4 = {9, 9, 9};
    vector<int> res4 = sol.plusOne(d4);
    cout << "Example 4 Output: ";
    printVector(res4); // Expected: [ 1 0 0 0 ]

    return 0;
}