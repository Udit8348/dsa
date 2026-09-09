class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // keep a min heap of the top k (ignore duplicates)
        // complete a linear scan
        // at the end return top of heap

        priority_queue<int, vector<int>, std::greater<int>> pq;

        for (auto n : nums) {
            if (pq.size() < k) {
                pq.push(n);
            } else {
                if (n > pq.top()) {
                    pq.pop();
                    pq.push(n);
                }
            }
        }

        return pq.top();
    }
};
