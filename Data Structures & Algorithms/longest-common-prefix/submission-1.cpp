class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // vertical line test
        string oracle = strs[0];

        for (int i = 0; i <= 200; i++) {
            for (const auto& s: strs) {
                // hit a failure, so this is the boundry of the lcp
                if (i == s.length() || s[i] != oracle[i]) {
                    return s.substr(0,i);
                }
            }
        }

        return oracle;
    }
};