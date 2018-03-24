class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        
        int start = 0, end = len - 1;
        if(nums[start] < nums[end]) return nums[start];
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[start] < nums[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return nums[end];
    }
};