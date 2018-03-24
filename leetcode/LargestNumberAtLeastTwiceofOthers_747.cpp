class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = -1, secMaxIdx = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(maxIdx < 0 || nums[i] > nums[maxIdx]) {
                secMaxIdx = maxIdx;
                maxIdx = i;
            } else if(secMaxIdx < 0 || nums[i] > nums[secMaxIdx]) {
                secMaxIdx = i;
            }
        }
        if(nums[maxIdx] - nums[secMaxIdx] < nums[secMaxIdx]) return -1;
        return maxIdx;
    }
};