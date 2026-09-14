class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // handle three regimes based on 
        // 1) intervals strictly ending before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2) intervals that overlap (start before end, but skipped previous conditional, so they exceed when newInterval starts!)
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // 3) intervals that are remaining (strictly after newInterval)
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
        
    }
};
