class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int hei = dungeon.size();
        int wid = dungeon[0].size();
        vector<vector<int>> dp(hei + 1, vector<int>(wid + 1, INT_MAX));
        dp[hei - 1][wid - 1] = max(1 - dungeon[hei - 1][wid - 1], 1);
        for(int i = hei - 1; i >= 0; --i)
            for(int j = wid - 1; j >= 0; --j) {
                if(i == hei - 1 && j == wid - 1) continue;
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        return dp[0][0];
    }
};