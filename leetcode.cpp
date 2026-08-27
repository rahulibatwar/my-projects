#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;

        string ans(len, '?');
        vector<bool> fixed(len, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (ans[i] == '?') {
                ans[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;
                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            char original = ans[i + j];
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    ans[i + j] = c;
                                    break;
                                }
                            }
                            
                            bool valid = true;
                            for (int k = 0; k <= i; k++) {
                                if (str1[k] == 'F') {
                                    bool m_check = true;
                                    for (int l = 0; l < m; l++) {
                                        if (ans[k + l] != str2[l]) {
                                            m_check = false;
                                            break;
                                        }
                                    }
                                    if (m_check) {
                                        valid = false;
                                        break;
                                    }
                                }
                            }

                            if (valid) {
                                changed = true;
                                break;
                            } else {
                                ans[i + j] = original;
                            }
                        }
                    }
                    if (!changed) return "";
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string str1 = "TFTF", str2 = "ab";
    cout << "Test Case 1 Output: " << sol.generateString(str1, str2) << " (Expected: ababa)" << endl;

    return 0;
}