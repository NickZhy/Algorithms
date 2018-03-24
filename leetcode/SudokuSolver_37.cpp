typedef pair<int, int> pos; 
class Solution {
public:
    bool helper(vector<vector<char>>& board, 
                vector<pos>& wip, 
                vector<vector<bool>>& hasNumRow, 
                vector<vector<bool>>& hasNumCol, 
                vector<vector<bool>>& hasNumCell) {
        if(wip.size() == 0) 
            return true;
        
        pos p = wip.back();
        wip.pop_back();
        int row = p.first, col = p.second;
        int cell = (row / 3) * 3 + col / 3;
        for(int i = 0; i < 9; ++i) {
            if(!hasNumRow[row][i] && !hasNumCol[col][i] && !hasNumCell[cell][i]) {
                hasNumRow[row][i] = true;
                hasNumCol[col][i] = true;
                hasNumCell[cell][i] = true;
                board[row][col] = '1' + i;
                if(helper(board, wip, hasNumRow, hasNumCol, hasNumCell)) 
                    return true;
                hasNumRow[row][i] = false;
                hasNumCol[col][i] = false;
                hasNumCell[cell][i] = false;
                board[row][col] = '.';
            }
        }
        wip.push_back(p);
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> hasNumCol(9, vector<bool>(9, false));
        vector<vector<bool>> hasNumRow(9, vector<bool>(9, false));
        vector<vector<bool>> hasNumCell(9, vector<bool>(9, false));
        vector<pos> wip;
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    wip.push_back(pos(i, j));
                } else {
                    int num = board[i][j] - '1';
                    hasNumRow[i][num] = true;
                    hasNumCol[j][num] = true;
                    int cell = (i / 3) * 3 + j / 3;
                    hasNumCell[cell][num] = true;
                }
            }
        helper(board, wip, hasNumRow, hasNumCol, hasNumCell);
    }
};