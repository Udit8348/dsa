class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int last_a = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (last_a == a) {continue;}
            last_a = a;
            
            int remaining = 0 - a;
            
            int j = i + 1;
            int k = nums.size() - 1;

            // two pointer check for all valid & unique j / k pairs
            while (j < k) {
                int b = nums[j];
                int c = nums[k];

                int curr = b + c;
                if (curr == remaining) {
                    // once we get a sol, slide past any duplicate sols
                    res.push_back({a,b,c});
                    while (j < k && nums[j] == b) j++;
                    while (j < k && nums[k] == c) k--;
                } else if (curr > remaining) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return res;
    }
};
