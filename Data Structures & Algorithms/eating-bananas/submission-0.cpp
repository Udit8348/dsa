class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // since we can only consume one bin per hour, the max k should be max_of(piles)
        // koko needs to do smoething per bin so the min k is one
        // find minimum valid k binary searching this space
        // a valid k -> try something smaller
        // invlid k -> try something larger 

        int hi = INT_MIN;
        for (auto p : piles) {
            hi = max(hi, p);
        }
        
        int lo = 1;

        // the binary search bound `lo` is a proxy for the solution k at the end
        // bc even if we get a valid mid, it goes not gaurantee optimality

        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;

            // check validity
            int time = 0;
            int k = mid;
            for (auto p : piles) {
                time += ceil((double)p/k);
            }

            if (time <= h) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        return lo;

        
    }
};
