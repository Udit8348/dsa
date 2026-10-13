class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        int k = 0;
        
        for (int read = 0; read < nums.size(); read++) {
            int curr = nums[read];

            if (curr != val) {
                nums[write] = curr;
                write++;
                k++;
            }
        }
        return k;
    }
};