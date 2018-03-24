/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = 0;
        while(start < intervals.size() && newInterval.start > intervals[start].end) ++start;

        int end = start;
        while(end < intervals.size() && intervals[end].start <= newInterval.end) ++ end;
        
        if(end != start) {
            newInterval.start = min(intervals[start].start, newInterval.start);
            newInterval.end = max(intervals[end - 1].end, newInterval.end);
            intervals.erase(intervals.begin() + start, intervals.begin() + end);
        }
        intervals.insert(intervals.begin() + start, newInterval);
        return intervals;
    }
};