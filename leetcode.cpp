#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& currentPath,
                   vector<vector<string>>& results) {
        if (word == beginWord) {
            vector<string> validPath = currentPath;
            reverse(validPath.begin(), validPath.end());
            results.push_back(validPath);
            return;
        }

        for (const string& p : parents[word]) {
            currentPath.push_back(p);
            backtrack(p, beginWord, parents, currentPath, results);
            currentPath.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;

        if (dict.find(endWord) == dict.end()) {
            return results;
        }

        dict.erase(beginWord);

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);

        bool found = false;
        int wordLen = beginWord.length();

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;

            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < wordLen; i++) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        temp[i] = c;

                        if (dict.find(temp) != dict.end()) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar;
                }
            }

            for (const string& w : nextLevel) {
                dict.erase(w);
            }

            currentLevel = nextLevel;
        }

        if (found) {
            vector<string> currentPath = {endWord};
            backtrack(endWord, beginWord, parents, currentPath, results);
        }

        return results;
    }
};

void printResults(const vector<vector<string>>& res) {
    cout << "[\n";
    for (const auto& path : res) {
        cout << "  [ ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "\"" << path[i] << "\"" << (i + 1 < path.size() ? ", " : "");
        }
        cout << " ]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<string> list1 = {"hot", "dot", "dog", "lot", "log", "cog"}; //[cite: 21]
    cout << "Example 1 Output:\n";
    printResults(sol.findLadders("hit", "cog", list1));

    vector<string> list2 = {"hot", "dot", "dog", "lot", "log"}; //[cite: 21]
    cout << "\nExample 2 Output:\n";
    printResults(sol.findLadders("hit", "cog", list2));

    return 0;
}