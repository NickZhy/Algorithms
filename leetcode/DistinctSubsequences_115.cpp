class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        vector<vector<int>> dp(lenS + 1, vector<int>(lenT + 1));
        for(int i = 0; i <= lenS; ++i) dp[i][0] = 1;
        for(int i = 1; i <= lenS; ++i)
            for(int j = 1; j <= lenT; ++j) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        return dp[lenS][lenT];
    }
};