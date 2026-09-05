class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t n = s.size();
        size_t m = t.size();
        if (n != m) {return false;}

        std::array<int, 26> lut{}; // zero init like this since there is no ctor

        
        for (char c : s) {
            int index = c - 'a';
            lut[index]++;
        }

        for (char c : t) {
            int index = c - 'a';
            lut[index]--;
        }

        for (auto v : lut) {
            if (v) return false; // mismatch in historgram means they are not anagrams
        }

        return true;
        
    }
};
