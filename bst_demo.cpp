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

// BST mein element ko sahi jagah insert karne ka recursive function
Node* insertBST(Node* root, int val) {
    // Agar tree khali hai, toh naya node banakar wahi return kar do
    if (root == NULL) {
        return new Node(val);
    }

    // Agar value root se choti hai, toh left subtree mein jao
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } 
    // Agar value root se badi hai, toh right subtree mein jao
    else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Inorder traversal check karne ke liye ki sorting ho rahi hai ya nahi
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "--- DSA Masterclass: Binary Search Tree (BST) ---" << endl << endl;

    Node* root = NULL;
    
    // Elements ko insert karna shuru karte hain
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);

    cout << "Inorder Traversal (Sorted Output): ";
    inorder(root);
    cout << endl << "------------------------------------------------" << endl;

    return 0;
}