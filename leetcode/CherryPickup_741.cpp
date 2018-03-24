class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        dp[1][1] = grid[0][0];
        for(int t = 3; t <= 2 * N; ++t) {
            for(int i = min(t - 1, N); i > 0; --i)
                for(int j = min(t - 1, N); j > 0; --j) {
                    int a = grid[i - 1][t - i - 1];
                    int b = grid[j - 1][t - j - 1];
                    if(a == -1 || b == -1) {
                        dp[i][j] = -1;
                    } else {
                        int added = (i == j? a: a + b);
                        int m = max(max(dp[i - 1][j - 1], dp[i][j]), max(dp[i - 1][j], dp[i][j - 1]));
                        dp[i][j] = (m == -1? -1: m + added);
                    }
                }
        }
        return dp[N][N] == -1? 0: dp[N][N];
    }
};