class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) return true;
            int tmp = mid;
            while(tmp > start && nums[start] == nums[tmp]) --tmp;
            if(nums[start] <= nums[tmp]) {
                if(nums[start] <= target && target <= nums[tmp]) {
                    end = tmp;
                } else {
                    start = mid + 1;
                }
            } else {
                if(nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = tmp;
                }
            }
        }
        return false;
    }
};