/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // inline comparator defined for ADT Interval
        sort(intervals.begin(),
             intervals.end(), 
             [](Interval &a, Interval &b) -> bool {return a.start < b.start;}
        );

        for (int i = 1; i < intervals.size(); i++) {
            // lt since [a,b)
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
