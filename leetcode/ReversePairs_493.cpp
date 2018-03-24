class Solution {
public:
    int mergeSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        int mid = nums.size()/2 ;
        vector<int> first(nums.begin(), nums.begin() + mid);
        vector<int> second(nums.begin() + mid, nums.end());
        int p1 = mergeSort(first);
        int p2 = mergeSort(second);
        int i = 0, j = 0, p3 = 0;
        while(i < first.size() && j < second.size()) {
            if(first[i] > 2L * second[j]) {
                p3 += first.size() - i;
                ++j;
            } else {
                ++i;
            }
        }
        i = j = 0;
        int n = 0;
        while(i < first.size() && j < second.size()) {
            if(first[i] < second[j]) nums[n++] = first[i++];
            else nums[n++] = second[j++];
        }
        while(i < first.size())
            nums[n++] = first[i++];
        while(j < second.size())
            nums[n++] = second[j++];
        return p1 + p2 + p3;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums);
    }
};