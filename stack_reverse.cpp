#include <iostream>
#include <stack>  // C++ ki Standard Template Library (STL) Stack
#include <string>
using namespace std;

int main() {
    cout << "--- DSA Masterclass: String Reversal Using Stack ---" << endl << endl;

    string str = "RAHUL";
    cout << "Original String: " << str << endl;

    // 1. Ek character type ka stack banaya
    stack<char> s;

    // 2. String ke saare characters ko ek-ek karke stack mein PUSH kiya
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // 3. Stack se characters ko POP karke naya reverse string banaya
    string reversedStr = "";
    while (!s.empty()) {
        reversedStr += s.top(); // Top element ko uthaya
        s.pop();               // Stack se delete kiya
    }

    cout << "Reversed String: " << reversedStr << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}