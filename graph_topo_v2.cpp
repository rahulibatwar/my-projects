#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Directed edge (U -> V) add karne ka function
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); 
}

// Topological Sort ke liye DFS Helper
void topoSortHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topoSortHelper(neighbor, adj, visited, st);
        }
    }
    // Saare neighbors explore hone ke baad hi node stack mein jayega
    st.push(node);
}

void topologicalSort(const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoSortHelper(i, adj, visited, st);
        }
    }

    cout << "Topological Sort Order: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Topological Sorting (DAG) ---" << endl << endl;

    int V = 6; 
    vector<vector<int>> adj(V);

    // Dependencies setup
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    topologicalSort(adj, V);

    cout << "--------------------------------------------------" << endl;
    return 0;
}