class Solution {
public:
    void sortColors(vector<int>& nums) {
        // three regions, slide partitions to enforce boundaries
        int n = nums.size();
        int left_writer = 0;
        int right_writer = n - 1;

        int i = 0;
        while (i <= right_writer) {
            int curr = nums[i];
            if (curr == 0) {
                if (i > left_writer) {
                    swap(nums[i], nums[left_writer]);
                }
                left_writer++;
            } else if (curr == 2) {
                if (i < right_writer) {
                    swap(nums[i], nums[right_writer]);
                }
                right_writer--;
                i--;
            }
            i++;
        } 
    }
};