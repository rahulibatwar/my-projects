#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());

        for (auto& pair : mp) {
            result.push_back(move(pair.second));
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groups = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : groups) {
        cout << "[ ";
        for (const string& word : group) {
            cout << "\"" << word << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}