#include <iostream>
#include <vector>

using namespace std;

// Solves 4x4 Maze configuration
#define N 4 

bool isSafe(vector<vector<int>>& maze, int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool solveMazeUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        if (sol[x][y] == 1) return false;

        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol)) return true;
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;

        sol[x][y] = 0; // BACKTRACK
        return false;
    }
    return false;
}

int main() {
    cout << "--- DSA Masterclass: Rat in a Maze (C++) ---" << endl << endl;

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