class NumMatrix {
public:
    vector<vector<int>> rowSum;
    NumMatrix(vector<vector<int>> matrix) {
        int hei = matrix.size();
        int wid = hei? matrix[0].size(): 0;
        rowSum.resize(hei + 1);
        for(vector<int>& row: rowSum)
            row.resize(wid + 1);
        for(int i = 1; i <= matrix.size(); ++i)
            for(int j = 1; j <= matrix[0].size(); ++j)
                rowSum[i][j] = rowSum[i][j - 1] + matrix[i - 1][j - 1];
    }
    
    void update(int row, int col, int val) {
        int change = val - (rowSum[row + 1][col + 1] - rowSum[row + 1][col]);
        for(int j = col + 1; j < rowSum[0].size(); ++j)
            rowSum[row + 1][j] += change;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rst = 0;
        for(int i = row1 + 1; i <= row2 + 1; ++i) 
            rst += rowSum[i][col2 + 1] - rowSum[i][col1];
        return rst;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */