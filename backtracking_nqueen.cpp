#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be safely placed at board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) return false;
    }

    return true; // The position is safe for placement
}

// Recursive utility function to solve N-Queen problem using Backtracking
bool solveNQueenUtil(vector<vector<int>>& board, int col, int N) {
    // Base Case: If all queens are successfully placed
    if (col >= N) return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueenUtil(board, col + 1, N)) return true;

            // BACKTRACK: If placing queen here doesn't lead to a solution, remove the queen
            board[i][col] = 0;
        }
    }

    return false; // If the queen cannot be placed in any row in this column
}

int main() {
    cout << "--- DSA Masterclass: N-Queen Problem (Backtracking) ---" << endl << endl;

    int N = 4; // 4x4 Chess Board configuration
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Board Configuration: " << N << "x" << N << endl << endl;

    if (!solveNQueenUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
    } else {
        // Printing the final matrix layout (1 means Queen is placed)
        cout << "Final Matrix Layout Matrix (1 = Queen Position):" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i = 0; i < N; i++) {
            cout << "  ";
            for (int j = 0; j < N; j++) {
                if(board[i][j] == 1) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    return 0;
}