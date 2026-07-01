#include <iostream>
#include <algorithm> // max() function use karne ke liye
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

// 🎯 LOGIC FUNCTION: Tree ki Height/Depth nikalna
int calculateHeight(Node* root) {
    // Base Case: Agar tree khali hai, toh height 0 hai
    if (root == NULL) {
        return 0;
    }

    // 1. Left subtree ki height dhoodho
    int leftHeight = calculateHeight(root->left);

    // 2. Right subtree ki height dhoodho
    int rightHeight = calculateHeight(root->right);

    // 3. Jo bada hai use chunno aur khud ka +1 karke return karo
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    cout << "--- DSA Masterclass: Height of a Binary Tree ---" << endl << endl;

    // Tree Structure setup karte hain
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40); // 40 ki wajah se left side lambi ho gayi hai

    // Height calculate karte hain
    int height = calculateHeight(root);

    cout << "The Max Height (or Depth) of this Tree is: " << height << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}