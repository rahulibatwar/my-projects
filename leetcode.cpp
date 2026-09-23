#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    cout << "(() : " << sol.longestValidParentheses("(()") << " (Expected: 2)" << endl;
    cout << ")()()) : " << sol.longestValidParentheses(")()())") << " (Expected: 4)" << endl;
    cout << "Empty : " << sol.longestValidParentheses("") << " (Expected: 0)" << endl;

    return 0;
}