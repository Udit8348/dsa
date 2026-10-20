class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 is buffered sufficiently, both are sorted respectively, and 
        
        // fill the correct candidate from the back of each buffer
        int writer = m + n - 1;
        int r1 = m - 1;
        int r2 = n - 1;

        // keep going while there are still candidates for nums2 that need to be placed in nums1
        while (r2 >= 0) {
            if (r1 >= 0 && nums1[r1] > nums2[r2]) {
                nums1[writer] = nums1[r1];
                r1--;
            } else {
                nums1[writer]= nums2[r2];
                r2--;
            }
            writer--;
        }
        
    }
};