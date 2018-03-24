class Solution {
    public int[][] generateMatrix(int n) {
        int[][] rst = new int[n][n];
        int lo = 0, hi = n - 1;
        int num = 1;
        while(lo <= hi) {
            for(int i = lo; i <= hi; ++i)
                rst[lo][i] = num++;
            
            for(int i = lo + 1; i < hi; ++i)
                rst[i][hi] = num++;
            
            if(hi > lo) {
                for(int i = hi; i >= lo; --i)
                    rst[hi][i] = num++;
            }
            for(int i = hi - 1; i > lo; --i)
                rst[i][lo] = num++;
            --hi;
            ++lo;
        }
        return rst;
    }
}