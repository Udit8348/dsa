class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> candidates;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            auto it = candidates.find(n);
            if (it != candidates.end()) {
                return {it->second, i};
            } else {
                candidates[target-n] = i;
            }
        }

        return {};
        
    }
};
