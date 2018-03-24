class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> board;
    int bSize;
    TicTacToe(int n): board(n, vector<int>(n, 0)), bSize(n) { }
    
    bool checkRow(int row, int col, int player) {
        int tmp = row;
        while(tmp >= 0 && board[tmp][col] == player) --tmp;
        if(tmp != -1) return false;
        tmp = row;
        while(tmp < bSize && board[tmp][col] == player) ++tmp;
        return tmp == bSize;
    }
    
    bool checkCol(int row, int col, int player) {
        int tmp = col;
        while(tmp >= 0 && board[row][tmp] == player) --tmp;
        if(tmp != -1) return false;
        tmp = col;
        while(tmp < bSize && board[row][tmp] == player) ++tmp;
        return tmp == bSize;
    }
    
    bool checkDiag1(int row, int col, int player) {
        if(row != col) return false;
        int tmp = row;
        while(tmp >= 0 && board[tmp][tmp] == player) --tmp;
        if(tmp != -1) return false;
        tmp = row;
        while(tmp < bSize && board[tmp][tmp] == player) ++tmp;
        return tmp == bSize;
    }
    
    bool checkDiag2(int row, int col, int player) {
        if(row + col != bSize - 1) return false;
        int tmp = row;
        while(tmp >= 0 && board[tmp][bSize - 1 - tmp] == player) --tmp;
        if(tmp != -1) return false;
        tmp = row;
        while(tmp < bSize && board[tmp][bSize - 1 - tmp] == player) ++tmp;
        return tmp == bSize;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        if(checkRow(row, col, player) 
           || checkCol(row, col, player) 
           || checkDiag1(row, col, player) 
           || checkDiag2(row, col, player))
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */