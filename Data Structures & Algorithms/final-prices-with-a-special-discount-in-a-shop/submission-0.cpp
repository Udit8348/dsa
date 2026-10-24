class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        // difference to next greater element

        // index
        stack<int> st;

        for (int i = 0; i < prices.size(); i++) {

            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int old = prices[st.top()];
                int curr = prices[i];

                int delta = old - curr;

                prices[st.top()] = delta;

                st.pop();
            }
            st.push(i);
        }

        return prices;
    }
};
