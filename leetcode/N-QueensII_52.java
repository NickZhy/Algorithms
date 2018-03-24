class Solution {
    int helper(int row, int[] curr, boolean[] hasCol, boolean[] hasDiag1, boolean[] hasDiag2) {
        int len = curr.length;
        if(len == row) {
            return 1;
        }
        int rst = 0;
        for(int i = 0; i < len; ++i) {
            int diag1 = len - 1 + row - i;
            int diag2 = i + row;
            if(!hasCol[i] && !hasDiag1[diag1] && !hasDiag2[diag2]) {
                hasCol[i] = true;
                hasDiag1[diag1] = true;
                hasDiag2[diag2] = true;
                curr[row] = i;
                rst += helper(row + 1, curr, hasCol, hasDiag1, hasDiag2); 
                hasDiag1[diag1] = false;
                hasDiag2[diag2] = false;
                hasCol[i] = false;
            }
        }
        return rst;
    }
    public int totalNQueens(int n) {
        boolean[] hasCol = new boolean[n];
        boolean[] hasDiag1 = new boolean[2 *n - 1];
        boolean[] hasDiag2 = new boolean[2 * n - 1];
        int[] curr = new int[n];
        return helper(0, curr, hasCol, hasDiag1, hasDiag2);
    }
}