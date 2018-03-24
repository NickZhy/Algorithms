class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hei = matrix.size();
        if(!hei) return false;
        int wid = matrix[0].size();
        if(!wid) return false;
        
        int start = 0, end = hei * wid - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            int r = mid / wid, c = mid % wid;
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};