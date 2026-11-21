#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.length()) {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };[cite: 26]

    cout << boolalpha;
    cout << "Example 1 (\"ABCCED\"): " << sol.exist(board, "ABCCED") << " (Expected: true)\n";[cite: 26]
    cout << "Example 2 (\"SEE\"): " << sol.exist(board, "SEE") << " (Expected: true)\n";[cite: 26]
    cout << "Example 3 (\"ABCB\"): " << sol.exist(board, "ABCB") << " (Expected: false)\n";

    return 0;
}