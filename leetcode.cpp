#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string current = "1";

        for (int step = 2; step <= n; step++) {
            string nextSeq = "";
            int len = current.length();

            for (int i = 0; i < len; i++) {
                int count = 1;
                while (i + 1 < len && current[i] == current[i + 1]) {
                    count++;
                    i++;
                }
                nextSeq += to_string(count);
                nextSeq += current[i];
            }

            current = nextSeq;
        }

        return current;
    }
};

int main() {
    Solution sol;

    cout << "n = 1: " << sol.countAndSay(1) << " (Expected: 1)" << endl;
    cout << "n = 4: " << sol.countAndSay(4) << " (Expected: 1211)" << endl;

    return 0;
}