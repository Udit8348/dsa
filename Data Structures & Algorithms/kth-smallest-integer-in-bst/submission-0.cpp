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
    
    void dfs(TreeNode* root, int& ct, int & res, int k) {
        if (!root) return;
        
        dfs(root->left, ct, res, k);
        
        ct++;
        if (ct == k) {
            res = root->val;
            return;
        }


        dfs(root->right, ct, res, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {

        int res = 0;
        int ct = 0;

        dfs(root, ct, res, k);

        return res;
        
    }

};

