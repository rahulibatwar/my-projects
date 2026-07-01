#include <iostream>
#include <vector>

using namespace std;

#define N 4 // 4x4 Chessboard

// Function to print the chessboard solution
void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        cout << "  ";
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i] == 1) return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

// Recursive utility function to solve N-Queen
bool solveNQUtil(vector<vector<int>>& board, int col) {
    // Base Case: If all queens are placed
    if (col >= N) return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1)) return true;

            // BACKTRACK: If placing queen in board[i][col] doesn't lead to a solution
            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "--- DSA Masterclass: N-Queen Problem (C++) ---" << endl << endl;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
    } else {
        cout << "One of the valid configurations for 4-Queens:" << endl;
        printSolution(board);
    }

    return 0;
}