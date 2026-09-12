class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);     // Odd length: "aba"
            expand(i, i + 1); // Even length: "abba"
        }

        return s.substr(start, maxLen);
        
    }
};
