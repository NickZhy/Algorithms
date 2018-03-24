class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int hei = matrix.size();
        if(!hei) return 0;
        int wid = matrix[0].size();
        if(!wid) return 0;
        
        int maxSize = 0;
        vector<vector<int> >  dp(hei + 1, vector<int>(wid + 1, 0));
        for(int i = 1; i <= hei; ++i)
            for(int j = 1; j <= wid; ++j) {
                if(matrix[i - 1][j - 1] != '0') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    maxSize = max(maxSize, dp[i][j] * dp[i][j]);
                }
            }
        return maxSize;
    }
};