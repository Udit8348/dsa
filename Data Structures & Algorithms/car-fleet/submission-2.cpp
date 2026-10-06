class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int,double>> meta; // {pos, finish time}
        for (int i = 0; i < n; i++) {
            int pos = position[i];
            double time = (target - pos) / (double)speed[i];
            meta.emplace_back(pos, time);
        }

        // sort(meta.begin(), meta.end(), greater<int>());
        std::sort(meta.begin(), meta.end(), std::greater<pair<int,double>>());

        stack<double> st;
        for (auto m : meta) {
            if (st.empty() || st.top() < m.second) {
                st.push(m.second);
            }
        }


        return st.size();

        
    }
};
