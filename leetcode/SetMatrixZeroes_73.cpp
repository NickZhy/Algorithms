class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int hei = matrix.size();
        if(!hei) return;
        int wid = matrix[0].size();
        
        bool firstRow = false, firstCol = false;
        for(int i = 0; i < hei; ++i)
            for(int j = 0; j < wid; ++j) {
                if(!matrix[i][j]) {
                    if(i && j) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    } else {
                        if(!i) firstCol = true;
                        if(!j) firstRow = true;
                    }
                }
            }
        
        for(int i = 1; i < hei; ++i)
            if(!matrix[i][0])
                for(int j = 0; j < wid; ++j) matrix[i][j] = 0;
        
        for(int j = 1; j < wid; ++j)
            if(!matrix[0][j])
                for(int i = 0; i < hei; ++i) matrix[i][j] = 0;
        
        if(firstRow) for(int i = 0; i < hei; ++i) matrix[i][0] = 0; 
        if(firstCol) for(int j = 0; j < wid; ++j) matrix[0][j] = 0;
            
                
    }
};