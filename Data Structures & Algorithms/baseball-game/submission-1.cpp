class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> st;

        for (auto& op : operations) {
            if (op == "+") {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int dst = op1 + op2;

                st.push(op2);
                st.push(op1);
                st.push(dst);

            } else if (op == "D") {
                int op1 = st.top();
                int dst = op1 * 2;

                st.push(dst);

            } else if (op == "C") {
                st.pop();

            } else {
                // number
                int num = std::stoi(op);
                st.push(num);
            }
        }

        int res = 0;
        while (!st.empty()) {
            res += st.top(); st.pop();
        }

        return res;
    }
};