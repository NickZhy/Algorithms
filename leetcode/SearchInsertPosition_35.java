class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0 || nums[0] >= target) return 0;

        int s = 0, e = nums.length;
        while(s + 1 < e) {
            int mid = (s + e) / 2;
            if(nums[mid] < target) {
                s = mid;
            } else {
                e = mid;
            }
        }
        return e;
    }
}