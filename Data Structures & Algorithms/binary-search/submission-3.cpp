class Solution {
public:
    int search(vector<int>& nums, int target) {
        // half open

        int lo = 0;
        int hi = (int) nums.size();

        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            int v = nums[mid];

            if (v >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return (lo < (int)nums.size() && nums[lo] == target) ? lo : -1;
        
    }
};
