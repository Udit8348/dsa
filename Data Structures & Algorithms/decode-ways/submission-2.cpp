
// state: string length
// base case: n == 0 (length zero)
// dec tree to explore a[n] =
//      if (s[n-1] != '0'): res+= a[n-1];
//      if (10 <= s[n-2] <= 27): res+= a[n-2];

class Solution {
   public:
    int top_down(int n, string& s, vector<int>& memo) {
        // base case: the empty prefix has exactly one decoding (decode nothing)
        if (n == 0) return 1;
        if (memo[n] != -1) {
            return memo[n];
        }

        int res = 0;

        // candidate 1: decode the last char on its own; only valid for '1'-'9'
        if (s[n - 1] != '0') {
            res += top_down(n - 1, s, memo);
        }

        // candidate 2: decode the last two chars together; only valid for 10..26
        if (n >= 2) {
            int two = (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
            if (two >= 10 && two <= 26) {
                res += top_down(n - 2, s, memo);
            }
        }

        return memo[n] = res;
    }

    int numDecodings(string s) {
        vector<int> memo (s.size()+1, -1);
        memo[0] = 1;
        return top_down(s.size(), s, memo);
    }
};
