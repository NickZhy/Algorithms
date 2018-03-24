class Solution {
public:
    int strangePrinter(string s) {
        int len = s.size();
        if(!len) return 0;
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        for(int i = len; i >= 1; --i)
            for(int j = i; j <= len; ++j) {
                dp[i][j] = dp[i][j - 1] + 1;
                for(int k = i; k < j; ++k)
                    if(s[j - 1] == s[k - 1])
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j - 1]);
            }
        return dp[1][len];
    }
};