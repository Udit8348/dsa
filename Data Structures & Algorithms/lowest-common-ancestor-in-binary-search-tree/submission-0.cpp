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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case: leaf node is nothing useful (returns nullptr as a sentinel)
        if (root == nullptr) {return root;}

        // base case: found p or q so we can report back up the call stack (returns a valid node: either p / q)
        if (root == p || root == q) {
            return root;
        }

        // post order
        TreeNode* left_res = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_res = lowestCommonAncestor(root->right, p, q);


        // solution
        if (left_res && right_res) {return root;}

        // just pass along a leg
        if (!left_res) return right_res;
        if (!right_res) return left_res;
        
        return nullptr;
    }
};
