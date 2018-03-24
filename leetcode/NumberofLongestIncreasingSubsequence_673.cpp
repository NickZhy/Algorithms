class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<vector<int>> dp(len, vector<int>(2, 1)); // dp[i] the number of longest subseq ends with nums[i] and length
        int mLen = 1;
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i] && dp[j][1] + 1 >= dp[i][1]) {
                   if(dp[j][1] + 1 == dp[i][1]) {
                       dp[i][0] += dp[j][0];
                   } else {
                       dp[i][1] = dp[j][1] + 1;
                       dp[i][0] = dp[j][0];
                   }
                }
            }
            mLen = max(mLen, dp[i][1]);
        }
        int count = 0;
        for(auto p: dp)
            if(p[1] == mLen) count += p[0];
        return count;
    }
};