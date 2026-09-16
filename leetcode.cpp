#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    cout << "n = 2: " << sol.climbStairs(2) << " (Expected: 2)" << endl;
    cout << "n = 3: " << sol.climbStairs(3) << " (Expected: 3)" << endl;
    cout << "n = 4: " << sol.climbStairs(4) << " (Expected: 5)" << endl;

    return 0;
}