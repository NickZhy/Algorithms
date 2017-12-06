class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int vlen = matrix.size();
        if(!vlen) return;
        int hlen = matrix.size();
        if(!hlen) return;
        for(int i = 0; i < vlen; ++i)
            for(int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for(auto& row: matrix)
            reverse(row.begin(), row.end());
    }
};
