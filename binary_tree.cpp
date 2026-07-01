#include <iostream>
using namespace std;

// Tree ke ek single block (Node) ka structure
struct Node {
    int data;
    Node* left;   // Left child ka address
    Node* right;  // Right child ka address

    // Constructor naya node aasani se banane ke liye
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Tree ko samajhne ke liye ek simple print function (Preorder)
void printTree(Node* root) {
    if (root == NULL) return;

    cout << root->data << " "; // Pehle parent print hoga
    printTree(root->left);     // Phir left child par jayenge
    printTree(root->right);    // Phir right child par jayenge
}

int main() {
    cout << "--- DSA Masterclass: Introduction to Binary Tree ---" << endl << endl;

    // 1. Sabse pehle Root node banaya
    Node* root = new Node(10);

    // 2. Left aur Right children jode
    root->left = new Node(20);
    root->right = new Node(30);

    // 3. Left child ke bhi niche ek node joda (Leaf node)
    root->left->left = new Node(40);

    /*
          Hamara Tree aisa dikh raha hai:
                10
               /  \
              20   30
             /
            40
    */

    cout << "Tree Elements (Root -> Left -> Right): ";
    printTree(root);
    cout << endl << "--------------------------------------------------" << endl;

    return 0;
}