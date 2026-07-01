#include <iostream>
using namespace std;

int main() {
    cout << "--- DSA Masterclass: Graph Adjacency Matrix ---" << endl << endl;

    int vertices = 4; // Total 4 nodes hain (0, 1, 2, 3)
    
    // 4x4 ka matrix banaya aur shuruat mein sabko 0 se initialize kiya
    int adjMatrix[4][4] = {0};

    // Edges add karte hain (Undirected Graph)
    
    // Edge between 0 and 1
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;

    // Edge between 1 and 2
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;

    // Edge between 2 and 3
    adjMatrix[2][3] = 1;
    adjMatrix[3][2] = 1;

    // Edge between 3 and 0
    adjMatrix[3][0] = 1;
    adjMatrix[0][3] = 1;

    // Matrix ko print karke dekhte hain
    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;

    return 0;
}