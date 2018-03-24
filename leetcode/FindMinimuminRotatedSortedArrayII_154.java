class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length - 1;
        if(nums[start] < nums[end]) return nums[start];
        while(start + 1 < end) {
            int mid = (start + end) / 2;
            int tmp = mid;
            while(start < tmp && nums[tmp] == nums[start]) --tmp;
            if(nums[start] <= nums[tmp]) {
                start = mid;
            } else {
                end = tmp;
            }
        }
        return Math.min(nums[start], nums[end]);
    }
}