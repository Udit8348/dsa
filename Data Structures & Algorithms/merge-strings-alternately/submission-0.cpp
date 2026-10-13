class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0; 
        int j = 0;

        int n = word1.size();
        int m = word2.size();

        int alpha = min(n,m);

        string res = "";

        for (int ii = 0; ii < alpha; ii++) {
            res += word1[i++];
            res += word2[j++];

        }

        res+= word1.substr(alpha, n);
        res+= word2.substr(alpha, m);

        return res;
        
    }
};