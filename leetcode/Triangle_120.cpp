class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int hei = triangle.size();
        if(!hei) return 0;
        int wid = triangle[hei - 1].size();
        vector<int> dp(wid + 1, 0);
        for(int i = hei - 1; i >= 0; --i)
            for(int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        return dp[0];
    }
};