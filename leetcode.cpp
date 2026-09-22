#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (!node) return;

        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1 ट्री बनाते हैं: 1 -> right: 2 -> left: 3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << "(Expected: 1 3 2)" << endl;

    return 0;
}