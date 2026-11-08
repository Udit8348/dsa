class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // confirm assumption that we add it at the matching index
            if (nums[mid] == target) {
                return mid;
            } else  if (nums[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
        
    }
};