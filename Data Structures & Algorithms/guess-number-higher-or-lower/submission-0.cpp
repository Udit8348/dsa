class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int res = guess(mid);

            if (res == 0) return mid;
            if (res == -1) hi = mid - 1;  // mid too high
            else           lo = mid + 1;  // mid too low
        }

        return -1;  // unreachable if the API is consistent
    }
};