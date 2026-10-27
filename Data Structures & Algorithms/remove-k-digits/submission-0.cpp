class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // emulate stack interface using a vector
        string st;

        // step 1: greedy approach "asteroid collision" as many as possible
        for (char c : num) {
            while (k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // step 2: chopping from the bottom effectively shifts by power of 10
        st.resize(st.size() - k);

        // step 3: check for leading zeros
        auto pos = st.find_first_not_of('0');

        if (pos == string::npos) {
            return "0";
        } else {
            return st.substr(pos);
        }
    }
};
