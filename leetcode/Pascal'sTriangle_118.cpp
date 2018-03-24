class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return vector<vector<int>>();
        vector<vector<int>> rst(numRows);
        for(int i = 0; i < numRows; ++i) {
            rst[i].resize(i + 1);
            rst[i][0] = rst[i][i] = 1;
            for(int j = 1; j < i; ++j)
                rst[i][j] = rst[i - 1][j - 1] + rst[i - 1][j];
        }
        return rst;
    }
};