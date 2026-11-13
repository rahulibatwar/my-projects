#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();

            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            int numWords = j - i;
            int gaps = numWords - 1;
            string line = "";

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int totalChars = 0;
                for (int k = i; k < j; k++) {
                    totalChars += words[k].length();
                }

                int totalSpaces = maxWidth - totalChars;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacesPerGap + ((k - i) < extraSpaces ? 1 : 0);
                        line += string(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};

void printLines(const vector<string>& lines) {
    cout << "[\n";
    for (const string& line : lines) {
        cout << "  \"" << line << "\"\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    cout << "Example 1 Output:\n";
    printLines(sol.fullJustify(words1, 16));

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    cout << "\nExample 2 Output:\n";
    printLines(sol.fullJustify(words2, 16));

    return 0;
}