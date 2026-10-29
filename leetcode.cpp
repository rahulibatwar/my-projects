#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution sol;

    cout << "Example 1: " << sol.lengthOfLastWord("Hello World") << " (Expected: 5)\n";
    cout << "Example 2: " << sol.lengthOfLastWord("   fly me   to   the moon  ") << " (Expected: 4)\n";
    cout << "Example 3: " << sol.lengthOfLastWord("luffy is still joyboy") << " (Expected: 6)\n";

    return 0;
}