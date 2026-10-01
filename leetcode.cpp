#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        
        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    // Example 1 ट्री बनाते हैं
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* bSTIterator = new BSTIterator(root);

    cout << bSTIterator->next() << " (Expected: 3)" << endl;
    cout << bSTIterator->next() << " (Expected: 7)" << endl;
    cout << boolalpha << bSTIterator->hasNext() << " (Expected: true)" << endl;
    cout << bSTIterator->next() << " (Expected: 9)" << endl;
    cout << boolalpha << bSTIterator->hasNext() << " (Expected: true)" << endl;
    cout << bSTIterator->next() << " (Expected: 15)" << endl;
    cout << boolalpha << bSTIterator->hasNext() << " (Expected: true)" << endl;
    cout << bSTIterator->next() << " (Expected: 20)" << endl;
    cout << boolalpha << bSTIterator->hasNext() << " (Expected: false)" << endl;

    delete bSTIterator;
    return 0;
}