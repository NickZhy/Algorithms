class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0;
        int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int t = 0;
        while(true) {
            slow = nums[slow];
            t = nums[t];
            if(t == slow) break;
        }
        return slow;
    }
}