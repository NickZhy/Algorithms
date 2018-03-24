class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = 0, len = nums.size();
        while(i + 1 < len && nums[i + 1] >= nums[i]) ++i;
        if(i == len - 1) return 0;
        
        int j = len - 1;
        while(nums[j - 1] <= nums[j]) --j;
        
        int maxNum = nums[i], minNum = nums[j];
        for(int k = i; k <= j; ++k) {
            maxNum = max(maxNum, nums[k]);
            minNum = min(minNum, nums[k]);
        }
        while(i >= 0 && nums[i] > minNum) --i;
        while(j < nums.size() && nums[j] < maxNum) ++j;
        return j - i - 1;
    }
};