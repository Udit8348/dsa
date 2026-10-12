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
   private:
    int dfs_helper(TreeNode* node, int& dia) {
        // assumes each node is valud, so if its invalid we have to detract that assumption
        if (node == nullptr) {
            return -1;
        }

        int left_path = dfs_helper(node->left, dia);
        int right_path = dfs_helper(node->right, dia);

        // maximization stored in a data out
        dia = max(dia, left_path + right_path + 2);

        // local status passed recursively
        return max(left_path, right_path) + 1;
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs_helper(root, dia);
        return dia;
    }
};
