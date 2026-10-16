class Solution {
public:
    
    // basic subset assumes the input has no duplicates
    void backtrack(vector<int>& nums, int start, int state, int& res) {
        res += state;

        // i is basically the starting "budget" we can generate from, it shrinks as we continue so we naturally avoid exploring duplicates
        for (int i = start; i < nums.size(); i++) {
            // track
            state ^= nums[i];

            backtrack(nums, i + 1, state, res);

            // untrack
            state ^= nums[i];
        }
    }
    
    int subsetXORSum(vector<int>& nums) {
        if (nums.empty()) {return 0;}

        int res = 0;
        backtrack(nums, 0, 0, res);

        return res;
    }
};