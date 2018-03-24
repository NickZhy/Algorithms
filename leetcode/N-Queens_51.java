class Solution {
    void dumpRst(List<List<String>> rst, int[] curr) {
        int len = curr.length;
        List<String> r = new ArrayList<String>();
        for(int i = 0; i < len; ++i) {
            String tmp = "";
            for(int j = 0; j < len; ++j)
                tmp += (curr[i] == j ? 'Q': '.');
            r.add(tmp);
        }
        rst.add(r);
    }
    
    void helper(int row, int[] curr, boolean[] hasCol, boolean[] hasDiag1, boolean[] hasDiag2, List<List<String>> rst) {
        int len = curr.length;
        if(len == row) {
            dumpRst(rst, curr);
            return;
        }
        for(int i = 0; i < len; ++i) {
            int diag1 = len - 1 + row - i;
            int diag2 = i + row;
            if(!hasCol[i] && !hasDiag1[diag1] && !hasDiag2[diag2]) {
                hasCol[i] = true;
                hasDiag1[diag1] = true;
                hasDiag2[diag2] = true;
                curr[row] = i;
                helper(row + 1, curr, hasCol, hasDiag1, hasDiag2, rst); 
                hasDiag1[diag1] = false;
                hasDiag2[diag2] = false;
                hasCol[i] = false;
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        boolean[] hasCol = new boolean[n];
        boolean[] hasDiag1 = new boolean[2 *n - 1];
        boolean[] hasDiag2 = new boolean[2 * n - 1];
        int[] curr = new int[n];
        List<List<String>> rst = new ArrayList<List<String>>();
        helper(0, curr, hasCol, hasDiag1, hasDiag2, rst);
        return rst;
    }
}