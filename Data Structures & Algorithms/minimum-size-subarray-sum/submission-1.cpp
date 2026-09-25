class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int best = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (l <= r && sum >= target) {
                // typically length calc is best done by permitting overlapp and adding 1 to their ptr difference
                best = min(r - l + 1, best);
                sum -= nums[l];
                l++;
            }
        }

        return best == INT_MAX ? 0 : best;
    }
};