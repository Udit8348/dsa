class Solution {
// [0]
// [1, 2, 0]
// [2, 0, 0, 0]

public:
    void sortColors(vector<int>& nums) {
        // three regions, slide partitions to enforce boundaries (Dutch National Flag)
        int n = nums.size();
        int left_writer = 0;
        int right_writer = n - 1;

        int i = 0;
        while (i <= right_writer) {
            int curr = nums[i];
            if (curr == 0) {
                if (i > left_writer) {
                    // partition order invariant is always kept
                    swap(nums[i], nums[left_writer]);
                }
                left_writer++;
            } else if (curr == 2) {
                if (i < right_writer) {
                    // partition order invariant is lost if we swap a "lower" color back
                    swap(nums[i], nums[right_writer]);
                }
                right_writer--;

                // hold current pointer back to check what we "received"
                i--;
            }
            i++;
        } 
    }
};