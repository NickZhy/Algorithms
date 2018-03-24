class Solution {
    String getRange(long lower, long upper) {
        if(lower == upper) return "" + lower;
        return "" + lower + "->" + upper;
    }
    
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> rst = new ArrayList<String>();
        if(nums.length == 0) {
            rst.add(getRange(lower, upper));
            return rst;
        }

        if(lower < nums[0]) rst.add(getRange(lower, nums[0] - 1));
        int idx = 0;
        while(idx + 1 < nums.length) {
            while(idx + 1 < nums.length && nums[idx + 1] <= nums[idx] + 1L) ++idx;
            if(idx + 1 < nums.length) rst.add(getRange(nums[idx] + 1L, nums[idx + 1] - 1L));
            ++idx;
        }
        idx = nums.length - 1;
        if(nums[idx] < upper) rst.add(getRange(nums[idx] + 1L, upper));
        return rst;
    }
}