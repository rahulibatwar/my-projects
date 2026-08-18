#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

int reverseInteger(int n) {
    int revNum = 0;

    while (n != 0) {
        int rem = n % 10;

        // Overflow checks
        if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
            return 0; // Return 0 if reversing causes integer overflow
        }

        revNum = (revNum * 10) + rem;
        n /= 10;
    }

    return revNum;
}

int main() {
    int num = 125;
    cout << "Original: " << num << endl;
    cout << "Reversed: " << reverseInteger(num) << endl; // Output: 521
    return 0;
}