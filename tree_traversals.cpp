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

// 1. PREORDER: Root -> Left -> Right
void printPreorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// 2. INORDER: Left -> Root -> Right
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);   // Pehle left subtree complete karo
    cout << root->data << " ";  // Phir root print karo
    printInorder(root->right);  // Phir right subtree par jao
}

// 3. POSTORDER: Left -> Right -> Root
void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);  // Pehle left subtree
    printPostorder(root->right); // Phir right subtree
    cout << root->data << " ";   // Sabse aakhiri mein root print karo
}

int main() {
    cout << "--- DSA Masterclass: All Tree Traversals ---" << endl << endl;

    // Tree Setup
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << "Preorder Traversal : ";
    printPreorder(root);
    cout << endl;

    cout << "Inorder Traversal  : ";
    printInorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    printPostorder(root);
    cout << endl;

    cout << "--------------------------------------------" << endl;
    return 0;
}