class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        if(len == 1) return nums[0];

        vector<int> dp(len, 0);
        dp[0] = 0; dp[1] = nums[1];
        for(int i = 2; i < len; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        
        int sol1 = dp[len - 1];
        
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        
        int sol2 = dp[len - 2];
        return max(sol1, sol2);
    }
};