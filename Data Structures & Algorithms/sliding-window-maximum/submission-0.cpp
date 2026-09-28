class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // {val, i}
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq;
        vector<int> output;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
            
            // gate candidates using index and size k to enforce fixed window size
            if (i >= k - 1) {
                while (pq.top().second <= i-k) {
                    pq.pop();
                }
                output.push_back(pq.top().first);
            }
        }

        return output;
    }
};
