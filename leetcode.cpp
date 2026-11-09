#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int low = 1;
        int high = x / 2;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (x = 4): " << sol.mySqrt(4) << " (Expected: 2)\n"; //[cite: 20]
    cout << "Example 2 (x = 8): " << sol.mySqrt(8) << " (Expected: 2)\n"; //[cite: 20]
    cout << "Test 3 (x = 0): " << sol.mySqrt(0) << " (Expected: 0)\n";
    cout << "Test 4 (x = 1): " << sol.mySqrt(1) << " (Expected: 1)\n";
    cout << "Test 5 (x = 2147395599): " << sol.mySqrt(2147395599) << " (Expected: 46339)\n";

    return 0;
}