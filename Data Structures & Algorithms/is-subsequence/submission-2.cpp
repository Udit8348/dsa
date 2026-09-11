class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lis = 0;

        int n = s.size();
        int m = t.size();

        // if (m == 0 || n == 0) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                } else {
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                }
            }
        }

        return dp[n][m] >= n;
    }
};