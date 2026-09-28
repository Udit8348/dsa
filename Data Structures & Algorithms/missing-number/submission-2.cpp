class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int target = nums.size();

        // generate do-undo pairs with i and n : nums
        for (int i = 0; i < nums.size(); i++) {
            target ^= (i ^ nums[i]);
        }

        return target;
    }
};
