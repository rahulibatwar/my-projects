#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
private:
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node) {
        if (!node) return nullptr;

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
};

int main() {
    // 4 नोड्स का ग्राफ तैयार करते हैं (1-2-3-4-1 साइकिल)
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Solution sol;
    Node* clonedRoot = sol.cloneGraph(node1);

    cout << "Original Node 1 address: " << node1 << endl;
    cout << "Cloned Node 1 address:   " << clonedRoot << " (Must be different)" << endl;
    cout << "Cloned Node 1 value:     " << clonedRoot->val << " (Expected: 1)" << endl;

    return 0;
}