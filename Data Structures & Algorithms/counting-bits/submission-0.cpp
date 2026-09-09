class Solution {
public:
    
    vector<int> countBits(int n) {
        // can break down to smaller binary representations by removing one's digit
        vector<int>dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            // previous sub problem's contribution
            int prev = dp[i>>1];
            
            // current number's contribution
            int curr = i & 1;

            dp[i] = curr + prev;
        }
        return dp;
    }
};
