class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        int idx = 1;
        while(idx < len && nums[idx] == nums[idx - 1]) ++idx;
        if(idx == len) return 1;
        
        bool increase = nums[idx] > nums[idx - 1];
        int maxLen = 1;
        while(idx < len) {
            if(increase) {
                while(idx < len && nums[idx] >= nums[idx - 1]) ++idx;
            } else {
                while(idx < len && nums[idx] <= nums[idx - 1]) ++idx;
            }
            increase = !increase;
            ++maxLen;
        }
        return maxLen;
    }
};