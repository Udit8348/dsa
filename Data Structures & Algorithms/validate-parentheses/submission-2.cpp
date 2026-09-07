class Solution {
public:
    bool isValid(string s) {

        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {

                if (st.size() > 0) {
                    // cout << "has something" << endl;
                    if ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '{' && c == '}')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return st.size() == 0;
        
    }
};
