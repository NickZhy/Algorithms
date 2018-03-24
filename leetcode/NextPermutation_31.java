class Solution {
    void swap(int[] nums, int s, int e) {
        int t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }
    void reverse(int[] nums, int s, int e) {
        while(s < e) 
            swap(nums, s++, e--);
    }
    public void nextPermutation(int[] nums) {
        if(nums.length <= 1) return;
        int idx = nums.length - 1;
        while(idx > 0 && nums[idx - 1] >= nums[idx]) --idx;
        if(idx > 0) {
            int pos = nums.length - 1;
            while(nums[pos] <= nums[idx - 1]) --pos;
            swap(nums, pos, idx - 1);
        }
        reverse(nums, idx, nums.length - 1);
    }
}