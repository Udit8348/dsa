class Solution {
private:
    static int order_index[26];
    
    static bool compare(const string& a, const string& b) {
        for (int i = 0; i < min(a.length(), b.length()); i++) {
            if (a[i] != b[i]) {
                return order_index[a[i] - 'a'] < order_index[b[i] - 'a'];
            }
        }
        return a.size() < b.size();
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            char c = order[i];
            order_index[c-'a'] = i;
        }

        return is_sorted(words.begin(), words.end(), compare);
    }
};

int Solution::order_index[26];

