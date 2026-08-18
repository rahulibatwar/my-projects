#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    // Condition 1: n must be greater than 0
    // Condition 2: (n & (n - 1)) must evaluate to 0
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num = 32;
    if (isPowerOfTwo(num)) {
        cout << num << " is a power of 2." << endl;
    } else {
        cout << num << " is NOT a power of 2." << endl;
    }
    return 0;
}