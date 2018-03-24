class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int idx = len - 1;
        while(idx >= 0 && digits[idx] == 9) --idx;
        if(idx < 0) {
            int[] rst = new int[len + 1];
            rst[0] = 1;
            return rst;
        }
        
        int[] rst = new int[len];
        rst[idx] = digits[idx] + 1;
        --idx;
        while(idx >= 0) {
            rst[idx] = digits[idx];
            --idx;
        }
        return rst;
    }
}