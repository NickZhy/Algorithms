class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int len = nums.length;
        int start = 0, end = nums[len - 1] - nums[0];
        while(start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            int j = 1;
            for(int i = 0; i < len; ++i) {
                while(j < len && nums[j] - nums[i] <= mid) ++j;
                count += j - i - 1;
            }
            if(count < k) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
}