#define INF numeric_limits<int>::max()
#define -INF numeric_limits<int>::min()
class Solution {
public:
    int arrMin(vector<int>& a, vector<int>& b, int p1, int p2) {
        int m1 = p1 < a.size()? a[p1]: INF;
        int m2 = p2 < b.size()? b[p2]: INF;
        return min(m1, m2);
    }
    
    int arrMax(vector<int>& a, vector<int>& b, int p1, int p2) {
        int m1 = p1 >= 0? a[p1]: -INF;
        int m2 = p2 >= 0? b[p2]: -INF;
        return max(m1, m2);
    }
    
    int check(vector<int>& nums1, vector<int>& nums2, int pos1, int pos2) {
        if(pos2 < 0)
            return 1;
        if(pos2 > nums2.size())
            return -1;
        if(pos1 > 0 && pos2 < nums2.size() && nums1[pos1 - 1] > nums2[pos2])
            return 1;
        if(pos2 > 0 && pos1 < nums1.size() && nums2[pos2 - 1] > nums1[pos1])
            return -1;
        return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1.size() > nums2.size() ? nums1: nums2;
        vector<int>& b = nums1.size() > nums2.size() ? nums2: nums1;
        int len = a.size() + b.size();
        int start = 0, end = a.size(), pos1, pos2;
        while(start < end) {
            pos1 = (start + end) / 2;
            pos2 = len / 2 - pos1;
            int t = check(a, b, pos1, pos2);
            if(t == 0) break;
            if(t == 1) end = pos1;
            else start = pos1 + 1;
        }
        float rst = 0;
        if(len % 2) {
            rst = arrMin(a, b, pos1, pos2);
        } else {
            rst = (arrMax(a, b, pos1 - 1, pos2 - 1) + arrMin(a, b, pos1, pos2)) / 2.0;
        }
        return rst;
    }
};
