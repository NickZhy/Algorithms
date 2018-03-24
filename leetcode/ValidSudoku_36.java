class Solution {
    public boolean isValidSudoku(char[][] board) {
        if(board.length != 9 || board[0].length != 9) return false;
        boolean rowHas[][] = new boolean[9][9];
        boolean colHas[][] = new boolean[9][9];
        boolean cellHas[][] = new boolean[9][9];
        
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int cell = (i / 3) * 3 + j / 3;
                    if(rowHas[i][num]) return false;
                    if(colHas[j][num]) return false;
                    if(cellHas[cell][num]) return false;
                    rowHas[i][num] = colHas[j][num] = cellHas[cell][num] = true;
                }
        return true;
    }
}