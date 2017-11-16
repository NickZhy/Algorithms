class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        for(int i = 0; i <= n; ++i) 
            dp[i][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] == INT_MAX? INT_MAX: dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = dp[i-1][j] == INT_MAX? INT_MAX: dp[i-1][j] + 1;
                }
            }
        }
        int mi = INT_MAX;
        int pos = 0;
        for(int i = 0; i <= n; ++i) {
            if(dp[i][m] < mi) {
                mi = dp[i][m];
                pos = i;
            }
        }
        if(mi == INT_MAX) return "";
        return S.substr(pos - mi, mi);
    }
};
