class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        std::unordered_set<int> lut;
        lut.reserve(min(n, k+1));       // max window size

        for (int i = 0; i < n; i++) {
            if (!lut.insert(nums[i]).second) return true;
            if (i >= k) lut.erase(nums[i-k]);
        }

        return false;
        
    }
};