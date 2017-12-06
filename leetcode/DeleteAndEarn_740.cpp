class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for(auto n: nums)
            ++count[n];
        vector<int> dp(10001, 0);
        dp[1] = count[1];
        for(int i = 2; i < 10001; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i );
        }
        return dp[10000];
    }
};
