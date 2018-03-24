class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int hei = obstacleGrid.length;
        if(hei == 0) return 0;
        int wid = obstacleGrid[0].length;
        if(wid == 0) return 0;
        int[][] dp = new int[hei][wid];
        if(obstacleGrid[0][0] == 1) return 0;
        
        dp[0][0] = 1;
        for(int i= 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j) 
                if(obstacleGrid[i][j] == 0) {
                    if(i > 0)
                        dp[i][j] += dp[i - 1][j];
                    if(j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
        return dp[hei - 1][wid - 1];
    }
}