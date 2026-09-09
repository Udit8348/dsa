class Solution {
public:
    
    void dfs(TreeNode* root, int max_so_far, int& data_out) {
        if (root == nullptr) {
            return;
        }

        // pre order
        if (root->val >= max_so_far) {
            data_out++;
            max_so_far = root->val;
        }
        
        dfs(root->left, max_so_far, data_out);
        dfs(root->right, max_so_far, data_out);

        return;
    }
    
    int goodNodes(TreeNode* root) {
        // pre-order exploration, track max_so_far of each path
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};
