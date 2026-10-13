class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // classic histogram & heap solution
        std::unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        // freq, val
        using entry = pair<int, int>;
        priority_queue<entry, vector<entry>, greater<>> pq;

        // limit the pq size to k for nlog(k) complexity
        for (auto p : freq) {
            entry t = {p.second, p.first};
            pq.push(t);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            auto r = pq.top();
            res.push_back(r.second);
            pq.pop();
        }

        return res;
        
    }
};
