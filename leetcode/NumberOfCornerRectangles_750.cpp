class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int count = 0;
        int hei = grid.size(), wid = grid[0].size();
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j)
                if(grid[i][j]) {
                    for(int k = i + 1; k < hei; ++k)
                        if(grid[k][j]) {
                            for(int m = j + 1; m < wid; ++m) 
                                if(grid[i][m] && grid[k][m])
                                    ++count;
                        }
                }
        return count;
    }
};