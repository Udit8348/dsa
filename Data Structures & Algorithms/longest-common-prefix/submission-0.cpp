class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // feels like pumping lemma for some reason
        for (int i = 0;i < strs[0].length(); i++) {
            int ct = 0;
            for (string s : strs) {
                if (i == s.length() || s[i] != strs[0][i]) {
                    return s.substr(0, i);
                }
            }
        }
        return strs[0];   
    }
};