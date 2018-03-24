class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void flip(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < len / 2; ++j)
                swap(matrix[i][j], matrix[i][len - 1 - j]);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flip(matrix);
    }
};