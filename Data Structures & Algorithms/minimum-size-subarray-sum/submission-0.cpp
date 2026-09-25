class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // prefix sum over input, in place
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                continue;
            }

            int threshold = nums[i] - target;
            auto it = std::upper_bound(nums.begin(), nums.begin() + i, threshold);            
            int j = std::distance(nums.begin(), it) - 1;

            res = min(res, i - j);
        }

        return res == INT_MAX ? 0 : res;
    }
};