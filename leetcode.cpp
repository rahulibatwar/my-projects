#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Overflow Check
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution sol;

    int x1 = 123;
    cout << "Test Case 1 Output: " << sol.reverse(x1) << " (Expected: 321)" << endl;

    int x2 = -123;
    cout << "Test Case 2 Output: " << sol.reverse(x2) << " (Expected: -321)" << endl;

    int x3 = 120;
    cout << "Test Case 3 Output: " << sol.reverse(x3) << " (Expected: 21)" << endl;

    return 0;
}