class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int hei = board.size();
        if(hei == 0) return;
        int wid = board[0].size();
        if(wid == 0) return;
        
        int BORN = -1, DEAD = -2;
        int neiX[] = {0,  0,  1,  1,  1, -1, -1, -1};
        int neiY[] = {1, -1,  1, -1,  0,  1, -1,  0};
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j) {
                int count = 0;
                for(int n = 0; n < 8; ++n) {
                    int y = neiY[n] + i, x = neiX[n] + j;
                    if(x >= 0 && x < wid && y >= 0 && y < hei)
                        count += (board[y][x] == DEAD || board[y][x] == 1);
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = DEAD;
                } else if(count == 3 && board[i][j] == 0) {
                    board[i][j] = BORN;
                }
            }
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j)
                if(board[i][j] == BORN) 
                    board[i][j] = 1;
                else if(board[i][j] == DEAD)
                    board[i][j] = 0;
    }
};