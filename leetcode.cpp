#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Even indices (0 aur 2) check: Ya toh match ho ya swapping ke baad match ho
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // Odd indices (1 aur 3) check: Ya toh match ho ya swapping ke baad match ho
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        
        return evenMatch && oddMatch;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1_1 = "abcd", s2_1 = "cdab";
    cout << "Test Case 1 Output: " << (sol.canBeEqual(s1_1, s2_1) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 2
    string s1_2 = "abcd", s2_2 = "dacb";
    cout << "Test Case 2 Output: " << (sol.canBeEqual(s1_2, s2_2) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}