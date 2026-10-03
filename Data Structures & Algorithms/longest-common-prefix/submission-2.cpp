class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // randomly choose any candidate string because the LCP is valid for all strings
        string oracle = strs[0];

        // vertical line test
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