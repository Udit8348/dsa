class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size() - 1;

        int left = numbers[lo];
        int right = numbers[hi];
        while (left + right != target) {
            if (left + right > target) {
                hi--;
            } else {
                lo++;
            }
            left = numbers[lo];
            right = numbers[hi];
        }

        return {lo+1, hi+1};
        
    }
};
