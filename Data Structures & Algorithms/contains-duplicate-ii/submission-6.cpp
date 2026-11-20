class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {return false;}

        int lo = 0;
        int hi = 0;

        int n = nums.size();

        unordered_set<int> lut;
        lut.reserve(n);

        // saturate the window to max size, then slide

        
    

        while (hi <= k && hi < n) {
            if (lut.count(nums[hi]) == 1) {
                return true;
            } else {
                lut.insert(nums[hi]);
            }

            cout << hi << endl;

            hi++;
        }

        // strange case when k >= n
        if (hi == n) return false;

        // slide
        lut.erase(nums[lo]);
        lo++;


        while (hi < n) {
            cout << hi << endl;
            if (lut.count(nums[hi]) == 1) {
                return true;
            } else {
                lut.insert(nums[hi]);
            }

            hi++;
            lut.erase(nums[lo]);
            lo++;
        }

        return false;



        
    }
};