class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());
        for (int n : nums) ++freq[n];

        using Entry = std::pair<int, int>;  // {count, value}
        std::priority_queue<Entry, std::vector<Entry>, std::greater<>> pq;

        for (const auto& [value, count] : freq) {
            pq.emplace(count, value);
            if (pq.size() > k) pq.pop();
        }

        std::vector<int> res;
        res.reserve(pq.size());
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};