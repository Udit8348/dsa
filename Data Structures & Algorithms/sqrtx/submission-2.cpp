class Solution {
public:
    int mySqrt(int x) {

        int lo = 0;
        int hi = x;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            long long res = 1L * mid * mid;

            if (res == (long long)x) {
                return mid;
            } else if (res > (long long) x) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};