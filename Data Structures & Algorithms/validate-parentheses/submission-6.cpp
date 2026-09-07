class Solution {
public:
    bool isValid(string s) {

        std::stack<char> st;
        char top = s[0];
        st.push(top);

        for (int i = 1; i < s.size(); i++) {

            // prefetch top to avoid repeated calls
            top = st.empty() ? '*' : st.top();
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}')) {
                 st.pop();
            } else {
                // no existing opening paren to match w/ a closing paren
                return false;
            }
        }

        return st.empty();
        
    }
};
