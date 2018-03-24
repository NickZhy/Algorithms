class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(!len) return 0;
        sort(citations.begin(), citations.end());
        if(citations[len - 1] == 0) return 0;
        int start = 1, end = len;
        while(start + 1 < end) {
            int mid = (start + end) / 2;
            if(citations[len - mid] >= mid) start = mid;
            else end = mid;
        }
        if(citations[len - end] >= end) return end;
        return start;
    }
};