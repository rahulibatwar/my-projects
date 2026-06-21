#include <iostream>
#include <vector>

using namespace std;

#define N 4 // Maze Size 4x4

// Function to check if x, y is safe for rat
bool isSafe(vector<vector<int>>& maze, int x, int y) {
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

// Recursive utility function to solve Maze problem using Backtracking
bool solveMazeUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    // Base Case: If rat reaches destination
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y)) {
        // Check if the current block is already part of solution path
        if (sol[x][y] == 1) return false;

        // Mark x, y as part of solution path
        sol[x][y] = 1;

        // Move forward in x direction (Right)
        if (solveMazeUtil(maze, x + 1, y, sol)) return true;

        // Move down in y direction (Down)
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;

        // BACKTRACK: If none of the above movements work
        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    cout << "--- DSA Masterclass: Rat in a Maze (C++) ---" << endl << endl;

    // 1 = Path, 0 = Wall
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<vector<int>> sol(N, vector<int>(N, 0));

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "Solution does not exist" << endl;
    } else {
        cout << "Final Solution Path Matrix (1 = Rat's Track):" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i = 0; i < N; i++) {
            cout << "  ";
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    return 0;
}