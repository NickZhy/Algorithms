class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0) return new ArrayList<Integer>();
        int left = 0, top = 0;
        int right = matrix[0].length - 1, bottom = matrix.length - 1;
        List<Integer> rst = new ArrayList<Integer>();
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; ++i)
                rst.add(matrix[top][i]);
            ++top;
            
            for(int i = top; i <= bottom; ++i)
                rst.add(matrix[i][right]);
            --right;
            
            if(top <= bottom) {
                for(int i = right; i >= left; --i)
                    rst.add(matrix[bottom][i]);
                --bottom;
            }
            
            if(left <= right) {
                for(int i = bottom; i >= top; --i)
                    rst.add(matrix[i][left]);
                ++left;
            }
        }
        return rst;
    }
}