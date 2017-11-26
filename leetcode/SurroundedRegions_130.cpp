class Solution {
public:
    void subSolve(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || i >= board.size()) return;
        if(j < 0 || j >= board[0].size()) return;
        if(visited[i][j]) return;
        if(board[i][j] == 'X') return;
        
        visited[i][j] = true;
        subSolve(board, visited, i + 1, j);
        subSolve(board, visited, i, j + 1);
        subSolve(board, visited, i - 1, j);
        subSolve(board, visited, i, j - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if(!h) return;
        int w = board[0].size();
        if(!w) return;
        
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for(int i = 0; i < h; ++i) {
            subSolve(board, visited, i, 0);
            subSolve(board, visited, i, w - 1);
        }
        for(int j = 1; j < w - 1; ++j) {
            subSolve(board, visited, 0, j);
            subSolve(board, visited, h - 1, j);
        }
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                if(!visited[i][j])
                    board[i][j] = 'X';
    }
};
