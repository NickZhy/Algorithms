class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hei = matrix.size();
        if(!hei) return false;
        int wid = matrix[0].size();
        int row = 0, col = wid - 1;
        while(row < hei && col >= 0) {
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) {
                --col;
            } else {
                ++row;
            }
        }
        return false;
    }
};