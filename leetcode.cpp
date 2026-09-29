#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;
        int s_len = s.size();

        if (s_len < total_len) return result;

        unordered_map<string, int> word_freq;
        for (const string& w : words) {
            word_freq[w]++;
        }

        for (int i = 0; i < word_len; i++) {
            unordered_map<string, int> current_freq;
            int left = i;
            int count = 0;

            for (int right = i; right + word_len <= s_len; right += word_len) {
                string word = s.substr(right, word_len);

                if (word_freq.find(word) != word_freq.end()) {
                    current_freq[word]++;
                    count++;

                    while (current_freq[word] > word_freq[word]) {
                        string left_word = s.substr(left, word_len);
                        current_freq[left_word]--;
                        count--;
                        left += word_len;
                    }

                    if (count == word_count) {
                        result.push_back(left);
                    }
                } else {
                    current_freq.clear();
                    count = 0;
                    left = right + word_len;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"foo", "bar"};
    vector<int> ans1 = sol.findSubstring("barfoothefoobarman", words1);
    cout << "Indices for Example 1: ";
    for (int idx : ans1) cout << idx << " ";
    cout << "(Expected: 0 9)" << endl;

    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> ans2 = sol.findSubstring("wordgoodgoodgoodbestword", words2);
    cout << "Indices for Example 2: ";
    for (int idx : ans2) cout << idx << " ";
    cout << "(Expected: empty)" << endl;

    return 0;
}