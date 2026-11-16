#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    cout << "[\n";
    for (const auto& row : mat) {
        cout << "  [ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(mat1);
    cout << "Example 1 Output:\n";
    printMatrix(mat1); // Expected: [[1,0,1],[0,0,0],[1,0,1]][cite: 20]

    vector<vector<int>> mat2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    sol.setZeroes(mat2);
    cout << "\nExample 2 Output:\n";
    printMatrix(mat2); // Expected: [[0,0,0,0],[0,4,5,0],[0,3,1,0]][cite: 20]

    return 0;
}