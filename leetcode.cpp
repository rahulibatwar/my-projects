#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            N = -N;
        }

        double ans = 1.0;
        double currentProduct = x;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= currentProduct;
            }
            currentProduct *= currentProduct;
            N /= 2;
        }

        return (n < 0) ? (1.0 / ans) : ans;
    }
};

int main() {
    Solution sol;

    cout << fixed << setprecision(5);
    cout << "Example 1: " << sol.myPow(2.00000, 10) << " (Expected: 1024.00000)\n";
    cout << "Example 2: " << sol.myPow(2.10000, 3) << " (Expected: 9.26100)\n";
    cout << "Example 3: " << sol.myPow(2.00000, -2) << " (Expected: 0.25000)\n";

    // Tricky test case:
    cout << setprecision(5);
    cout << "Tricky Case: " << sol.myPow(-0.999999968539456, -1669585506) << " (Expected: 191.06370)\n";

    return 0;
}