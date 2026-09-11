class Solution {
public:
    
    void dfs(vector<int>& nums, vector<int>& state, int start, vector<vector<int>>& res) {
        res.push_back(state);
        

        for (int i = start; i < nums.size(); i++) {
            state.push_back(nums[i]);    
            dfs(nums, state, i + 1, res);
            state.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {};
        vector<int> state {};
        int start = 0;

        dfs(nums, state, start, res);
        return res;

    }
};
