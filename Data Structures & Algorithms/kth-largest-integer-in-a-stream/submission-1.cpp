class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int capacity;

    KthLargest(int k, vector<int>& nums) : capacity(k) {
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
    }

    int add(int val) {
        if (pq.size() < capacity) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
