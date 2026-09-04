#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    // Test Cases
    string s1 = "()";
    cout << "Test Case 1 Output: " << (sol.isValid(s1) ? "true" : "false") << " (Expected: true)" << endl;

    string s2 = "()[]{}";
    cout << "Test Case 2 Output: " << (sol.isValid(s2) ? "true" : "false") << " (Expected: true)" << endl;

    string s3 = "(]";
    cout << "Test Case 3 Output: " << (sol.isValid(s3) ? "true" : "false") << " (Expected: false)" << endl;

    string s4 = "([])";
    cout << "Test Case 4 Output: " << (sol.isValid(s4) ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}