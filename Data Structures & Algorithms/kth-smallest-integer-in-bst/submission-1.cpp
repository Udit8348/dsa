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

    int dfs_prune(TreeNode* root, int& ct, int & res, int k) {
        if (!root) return -1;
        
        if (root->left) {
            int left_res = dfs_prune(root->left, ct, res, k);
            // short circuiting logic, so we exit as soon as we find the answer
            if (left_res != -1) {
                return left_res;
            }
        }
        
        
        ct++;
        if (ct == k) {
            return root->val;
        }

        if (root->right) {
            int right_res = dfs_prune(root->right, ct, res, k);
            if (right_res != -1) {
                return right_res;
            }
        }

        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {

        int res = 0;
        int ct = 0;

        res = dfs_prune(root, ct, res, k);

        return res;
        
    }

};

