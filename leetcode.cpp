#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution sol;

    int x1 = 121;
    cout << "Test Case 1 Output: " << (sol.isPalindrome(x1) ? "true" : "false") << " (Expected: true)" << endl;

    int x2 = -121;
    cout << "Test Case 2 Output: " << (sol.isPalindrome(x2) ? "true" : "false") << " (Expected: false)" << endl;

    int x3 = 10;
    cout << "Test Case 3 Output: " << (sol.isPalindrome(x3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}