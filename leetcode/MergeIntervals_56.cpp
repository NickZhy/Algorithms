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
    static bool cmp(Interval a, Interval b) {
        if(a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if(!intervals.size()) return vector<Interval>();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            Interval last = result.back();
            if(intervals[i].start > last.end) {
                result.push_back(intervals[i]);
            } else {
                result.pop_back();
                last.end = max(last.end, intervals[i].end);
                result.push_back(last);
            }
        }
        return result;
    }
};