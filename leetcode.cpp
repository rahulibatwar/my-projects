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
    vector<TreeNode*> buildTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> allTrees;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
};

int main() {
    Solution sol;

    vector<TreeNode*> trees = sol.generateTrees(3);
    cout << "Total Unique BSTs for n = 3: " << trees.size() << " (Expected: 5)" << endl;

    vector<TreeNode*> trees1 = sol.generateTrees(1);
    cout << "Total Unique BSTs for n = 1: " << trees1.size() << " (Expected: 1)" << endl;

    return 0;
}