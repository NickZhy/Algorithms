class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& l = nums1.size() > nums2.size()? nums1: nums2;
        vector<int>& s = nums1.size() > nums2.size()? nums2: nums1;
        int len1 = l.size();
        int len2 = s.size();
        
        int explen = (len1 + len2)/2;
        int start = max(0, explen - len2), end = min(len1, explen);
        int seg1, seg2;

        while(start <= end) {
            seg1 = start + (end - start) / 2;
            seg2 = max(explen - seg1, 0);
            
            if(seg1 > 0 && seg2 < len2 && l[seg1 - 1] > s[seg2]) {
                end = seg1 - 1;
            } else if(seg2 > 0 && seg1 < len1 && s[seg2 - 1] > l[seg1]) {
                start = seg1 + 1;
            } else {
                break;
            }
        }

        double min1 = seg1 > 0? l[seg1 - 1]: INT_MIN;
        double min2 = seg2 > 0? s[seg2 - 1]: INT_MIN;
        double max1 = seg1 < len1? l[seg1]: INT_MAX;
        double max2 = seg2 < len2? s[seg2]: INT_MAX;
        
        if((len1 + len2) % 2 == 0)
            return (max(min1, min2) + min(max1, max2)) / 2;
        
        return min(max1, max2);
    }
};