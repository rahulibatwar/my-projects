#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }

        if (stack.empty()) {
            return "/";
        }

        string simplified = "";
        for (const string& dir : stack) {
            simplified += "/" + dir;
        }

        return simplified;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (\"/home/\"): " << sol.simplifyPath("/home/") << " (Expected: /home)\n";[cite: 27, 28]
    cout << "Example 2 (\"/home//foo/\"): " << sol.simplifyPath("/home//foo/") << " (Expected: /home/foo)\n";[cite: 27, 28]
    cout << "Example 3 (\"/home/user/Documents/../Pictures\"): " 
         << sol.simplifyPath("/home/user/Documents/../Pictures") << " (Expected: /home/user/Pictures)\n";
    cout << "Example 4 (\"/../\"): " << sol.simplifyPath("/../") << " (Expected: /)\n";
    cout << "Example 5 (\"/.../a/../b/c/../d/./\"): " 
         << sol.simplifyPath("/.../a/../b/c/../d/./") << " (Expected: /.../b/d)\n";

    return 0;
}