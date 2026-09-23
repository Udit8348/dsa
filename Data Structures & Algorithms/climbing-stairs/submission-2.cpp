class Solution {

private:
    int top_down_recursive(int n) {
        // post order dfs from base cases back upwards
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 1;
        }

        return top_down_recursive(n-1) + top_down_recursive(n-2);
    }

    int memo_top_down_recursive(int n, vector<int>& memo) {
        // post order dfs from base cases back upwards

        if (memo[n] != -1) {
            return memo[n];
        }
        
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 1;
        }

        return memo[n] = memo_top_down_recursive(n-1, memo) + memo_top_down_recursive(n-2, memo);
    }


public:
    int climbStairs(int n) {
        // return top_down_recursive(n);

        vector<int> memo (n+1, -1);
        
        if (n == 0) return 1; // not a valid input by problem constraints
        if (n == 1) return 1;

        memo[0] = 1;
        memo[1] = 1;

        return memo_top_down_recursive(n, memo);


        
    }
};
