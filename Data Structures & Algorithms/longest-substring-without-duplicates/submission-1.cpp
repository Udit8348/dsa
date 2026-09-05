class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> freq{};
        int res = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            // count frequency of chars seen at right bound
            unsigned char c = s[r];
            freq[c]++;

            // move left bound until all dups are out of the window
            while (freq[c] > 1) {
                unsigned char exit_char = s[l];
                freq[exit_char]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
