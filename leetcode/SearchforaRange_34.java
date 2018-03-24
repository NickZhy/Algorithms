class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0 || nums[0] > target) 
            return new int[]{-1, -1};
        
        int s = 0, e = nums.length, start = 0;
        if(nums[s] < target) {
            while(s + 1 < e) {
                int mid = (s + e) / 2;
                if(nums[mid] < target) {
                    s = mid;
                } else {
                    e = mid;
                }
            }
            start = e;
        }
        
        if(start == nums.length || nums[start] != target) 
            return new int[]{-1, -1};
        
        s = start;
        e = nums.length - 1;
        int end = nums.length - 1;
        if(nums[e] > target) {
            while(s + 1 < e) {
                int mid = (s + e) / 2;
                if(nums[mid] == target) {
                    s = mid;
                } else {
                    e = mid;
                }
            }
            end = s;
        }
        
        return new int[]{start, end};
    }
}