class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);

        // build a reverse index
        unordered_map<int, int> map_index;
        for (int i = 0; i < nums1.size(); i++) {
            map_index[nums1[i]] = i;
        }

        stack<int> st;

        for (auto num : nums2) {
            int index = -1;
            while (!st.empty() && num > st.top()) {
                int val = st.top();
                st.pop();
                if (map_index.count(val)) res[map_index[val]] = num;
            }
            st.push(num);
        }

        return res;
    }
};