class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m);
        for(int i = 0; i < m; ++i) tmp[i] = nums1[i];
        int l1 = 0, l2 = 0 , k = 0;
        while(l1 < m && l2 < n) 
            nums1[k++] = tmp[l1] < nums2[l2] ? tmp[l1++]: nums2[l2++];
        while(l1 < m) nums1[k++] = tmp[l1++];
        while(l2 < n) nums1[k++] = nums2[l2++];
    }
};