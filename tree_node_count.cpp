#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 🎯 LOGIC FUNCTION: Total Nodes Count Karna
int countNodes(Node* root) {
    // Base Case: Agar tree khali hai, toh 0 nodes hain
    if (root == NULL) {
        return 0;
    }

    // Left ke saare nodes + Right ke saare nodes + 1 (khud current node)
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    cout << "--- DSA Masterclass: Count Total Nodes in a Binary Tree ---" << endl << endl;

    // Tree Setup
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    // Function Call
    int totalNodes = countNodes(root);

    cout << "Total Number of Nodes in this Tree: " << totalNodes << endl;
    cout << "--------------------------------------------------------" << endl;

    return 0;
}