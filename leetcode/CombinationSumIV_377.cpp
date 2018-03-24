class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len) return 0;
        
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; ++i)
            for(int j = 1; j <= len; ++j) {
                if(nums[j - 1] <= i) 
                    dp[i] +=  dp[i - nums[j - 1]];
            }
        
        return dp[target];
    }
};