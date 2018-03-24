class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(!len || !citations[len - 1]) return 0;
        int start = 1, end = len + 1;
        while(start + 1 < end) {
            int mid = (start + end) / 2;
            if(citations[len - mid] >= mid) start = mid;
            else end = mid;
        }
        return start;
    }
};