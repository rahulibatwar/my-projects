#include <iostream>
using namespace std;

int dectobin(int decNum) {
    int ans = 0;
    int p = 1; // Power variable (1, 10, 100, ...)

    while (decNum > 0) {
        int rem = decNum % 2; // Remainder (0 या 1)
        ans += (rem * p);
        p *= 10;
        decNum /= 2;          // Update decNum
    }

    return ans; // Binary from decimal
}

int main() {
    int decNum = 50; 

    for (int i=1; i<=10; i++) {
        cout << dectobin(i) << endl; // Print binary representation of i
    }
    return 0;
}