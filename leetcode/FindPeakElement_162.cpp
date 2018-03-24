class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        int start = 0, end = len - 1;
        if(nums[start + 1] < nums[start]) return start;
        if(nums[end - 1] < nums[end]) return end;
        while(start + 1 < end) {
            int mid = (start + end) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) return mid;
            if(nums[mid - 1] > nums[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if(nums[start] > nums[start + 1]) return start;
        return end;
    }
};