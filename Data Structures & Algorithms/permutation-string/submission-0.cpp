class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // slide a fixed window and ensure that we have all 26 char frequencies matching at least once

        // s2 is too short to contain a permutation of s1
        if (s1.size() > s2.size()) {
            return false;
        }


        vector<int> s1_hist(26, 0);
        vector<int> s2_hist(26, 0);

        // first initialize a window of fixed size s1
        for (int i = 0; i < s1.size(); i++) {
            s1_hist[s1[i]-'a']++;
            s2_hist[s2[i]-'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1_hist[i] == s2_hist[i]) {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            // check current window before executing shift inside of s2
            if (matches == 26) return true;

            // get the incoming char, determine how it affects matches
            char c = s2[r];
            int rIndex = c - 'a';

            bool beforeR = (s1_hist[rIndex] == s2_hist[rIndex]);
            s2_hist[rIndex]++;
            bool afterR = (s1_hist[rIndex] == s2_hist[rIndex]);

            if (beforeR && !afterR) matches--;
            if (!beforeR && afterR) matches++;

             // get the outgoing char, determine how it affects matches
            char cc = s2[l];
            int lIndex = cc - 'a';

            bool beforeL = (s1_hist[lIndex] == s2_hist[lIndex]);
            s2_hist[lIndex]--;
            bool afterL = (s1_hist[lIndex] == s2_hist[lIndex]);

            if (beforeL && !afterL) matches--;
            if (!beforeL && afterL) matches++;


            l++;

        }

        return matches == 26;

        
    }
};
