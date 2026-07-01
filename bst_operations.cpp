#include <iostream>
using namespace std;

// BST Node Structure Definition
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node in the BST
Node* insert(Node* root, int val) {
    // Agar tree khali hai, toh naya node bana kar return karo
    if (root == nullptr) {
        return new Node(val);
    }

    // Agar value root se choti hai, toh left subtree mein jao
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // Agar value root se badi hai, toh right subtree mein jao
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to search a value in the BST
bool search(Node* root, int target) {
    // Base Cases: root null hai (nahi mila) ya root par hi value mil gayi
    if (root == nullptr) return false;
    if (root->data == target) return true;

    // Target chota hai toh left mein dhoondo
    if (target < root->data) {
        return search(root->left, target);
    }
    // Target bada hai toh right mein dhoondo
    return search(root->right, target);
}

// In-order Traversal (Left, Root, Right) -> Yeh hamesha sorted elements deta hai
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    cout << "--- DSA Masterclass: Binary Search Tree (BST) Operations ---" << endl << endl;

    Node* root = nullptr;

    // Elements ko BST rule ke mutabik insert karte hain
    // Root banega 50
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order Traversal of BST (Always Sorted):" << endl;
    inorder(root);
    cout << endl << endl;

    // Searching operations evaluate karte hain
    int key1 = 60;
    int key2 = 95;

    cout << "Searching for " << key1 << " : " << (search(root, key1) ? "FOUND 🎉" : "NOT FOUND ❌") << endl;
    cout << "Searching for " << key2 << " : " << (search(root, key2) ? "FOUND 🎉" : "NOT FOUND ❌") << endl;

    cout << "------------------------------------------------------------" << endl;
    return 0;
}