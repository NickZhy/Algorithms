class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= N; ++i) {
            dp[i] = dp[i - 1] + 1;
            for(int j = 1; j <= i - 3; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[N];
    }
};