class Solution {
    public int minPathSum(int[][] grid) {
        int hei = grid.length;
        if(hei == 0) return 0;
        int wid = grid[0].length;
        if(wid == 0) return 0;
        
        int[][] dp = new int[hei][wid];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < hei; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        
        for(int j = 1; j < wid; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        for(int i = 1; i < hei; ++i)
            for(int j = 1; j < wid; ++j)
                dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);

        return dp[hei - 1][wid - 1];
    }
}