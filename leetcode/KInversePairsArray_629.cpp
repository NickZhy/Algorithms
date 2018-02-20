// This solution has potential space optimization.
class Solution {
public:
    int kInversePairs(int n, int k) {
        if(n < 1 || k > n * (n - 1) / 2) return 0;
        vector<vector<long> > dp(n + 1, vector<long>(k + 1, 0));
        for(int i = 1; i <= n; ++i)
            dp[i][0] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if(i <= j) dp[i][j] -= dp[i - 1][j - i];
                dp[i][j] = (dp[i][j] + 1000000007) % 1000000007;
            }
        }
        return dp[n][k];
    }
};
