class Solution {
private:
    // two pointer approach uses a helper function that starts with a left and right bound, and keeps expanding them outwards symmetrically (l/r are set based on odd or even pali detection)
    int count_palindrome_two_ptr(string s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;

            l--;
            r++;
        }

        return res;
    }


public:
    int countSubstrings(string s) {
        int ct = 0;
        for (int i = 0; i < s.size(); i++) {
            ct += count_palindrome_two_ptr(s, i, i);    // generate and check odd len palindromes from ith center
            ct += count_palindrome_two_ptr(s, i, i+1);  // same with odd len palindromes
        }

        return ct;
        
    }
};
