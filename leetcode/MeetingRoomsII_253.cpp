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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> rooms;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size(); ++i) {
            bool findRoom = false;
            for(int j = 0; j < rooms.size() && !findRoom; ++j) {
                if(rooms[j] <= intervals[i].start) {
                    rooms[j] = intervals[i].end;
                    findRoom = true;
                }
            }
            if(!findRoom) rooms.push_back(intervals[i].end);
        }
        return rooms.size();
    }
};