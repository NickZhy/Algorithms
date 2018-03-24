class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if(!intervals.size()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        set<int> rst;
        for(vector<int>& inv: intervals) {
            set<int>::iterator tmp = rst.lower_bound(inv[0]);
            if(tmp == rst.end()) {
                rst.insert(inv[1] - 1);
                rst.insert(inv[1]);
            } else if(next(tmp, 1) == rst.end()) {
                if(*tmp == inv[1]) rst.insert(inv[1] - 1);
                else rst.insert(inv[1]);
            }
        }
        return rst.size();
    }
};