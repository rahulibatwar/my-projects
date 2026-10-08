#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result,
               vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + (n - 1);
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n, board, result, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, board, result, cols, diag1, diag2);
        return result;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total distinct solutions for n = " << n << ": " << solutions.size() << " (Expected: 2)\n\n";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}