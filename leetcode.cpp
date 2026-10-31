#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long long)i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (n = 10): " << sol.countPrimes(10) << " (Expected: 4)\n";
    cout << "Example 2 (n = 0): " << sol.countPrimes(0) << " (Expected: 0)\n";
    cout << "Example 3 (n = 1): " << sol.countPrimes(1) << " (Expected: 0)\n";
    cout << "Test Case (n = 20): " << sol.countPrimes(20) << " (Expected: 8)\n";

    return 0;
}