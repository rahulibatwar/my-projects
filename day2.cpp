#include <iostream>
using namespace std;

int main() {
    int num = 10;        // एक सामान्य Variable
    int* ptr = &num;    // Pointer 'ptr' में 'num' का address स्टोर किया

    cout << "Value of num: " << num << endl;             // Output: 10
    cout << "Address of num (&num): " << &num << endl;   // Output: Memory address (e.g., 0x61ff08)
    cout << "Pointer storing address (ptr): " << ptr << endl; // Output: Same memory address
    cout << "Value at pointer (*ptr): " << *ptr << endl;  // Output: 10

    // Pointer के ज़रिए value बदलना
    *ptr = 25;
    cout << "Updated value of num: " << num << endl;     // Output: 25

    return 0;
}