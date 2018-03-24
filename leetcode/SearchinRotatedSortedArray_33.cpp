class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        if(!end) return -1;
        --end;
        while(start + 1 < end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) return mid;
            if(nums[start] < nums[mid]) {
                if(nums[start] <= target && target <= nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if(nums[mid] <= target && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        if(nums[start] == target) return start;
        if(nums[end] == target) return end;
        return -1;
    }
};