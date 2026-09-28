class Solution {
public:
    
    long long gf (int n) {
        long long res = ((1LL)*(n)*(n+1)) / 2;
        return res;
    }
    
    int missingNumber(vector<int>& nums) {
        long long target = gf(nums.size());
        for (int n : nums) {
            target -= (long long)(n);
        }

        return target;
        
    }
};