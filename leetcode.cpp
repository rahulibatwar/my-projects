#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        return isNegative ? -ans : ans;
    }
};

int main() {
    Solution sol;

    cout << "10 / 3: " << sol.divide(10, 3) << " (Expected: 3)" << endl;
    cout << "7 / -3: " << sol.divide(7, -3) << " (Expected: -2)" << endl;

    return 0;
}