/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    int dfs_helper(TreeNode* root, bool& valid) {

        if (root == nullptr) {
            return 0;
        }

        int left = dfs_helper(root->left, valid) + 1;
        int right = dfs_helper(root->right, valid) + 1;

        // balance is violated so capture that in the reference
        if (abs(left - right) > 1) {valid = false;}

        return max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool valid = true;
        int r = dfs_helper(root, valid);
        return valid;
    }
};
