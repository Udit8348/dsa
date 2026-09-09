class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // keep a min heap of the top k (ignore duplicates)
        // complete a linear scan
        // at the end return top of heap

        priority_queue<int, vector<int>, std::greater<int>> pq;

        for (auto n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
