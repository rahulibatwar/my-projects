#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << "n = 4: " << sol.canWinNim(4) << " (Expected: false)" << endl;
    cout << "n = 1: " << sol.canWinNim(1) << " (Expected: true)" << endl;
    cout << "n = 2: " << sol.canWinNim(2) << " (Expected: true)" << endl;
    cout << "n = 8: " << sol.canWinNim(8) << " (Expected: false)" << endl;

    return 0;
}