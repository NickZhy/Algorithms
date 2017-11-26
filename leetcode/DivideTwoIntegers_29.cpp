class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend) return 0;
        if(!divisor) return INT_MAX;

        long tmp = dividend;
        long dvs = divisor;
        tmp = abs(tmp);
        dvs = abs(dvs);
        
        long rst = 0;
        for(int i = 31; i >= 0; --i) {
            int t = 0;
            if(tmp >= (dvs << i)) {
                tmp = tmp - (dvs << i);
                t = 1;
            }
            rst = rst << 1| t;
        }
        
        if(dividend > 0 != divisor > 0)
            rst = -rst;
        if(rst > INT_MAX)
            return INT_MAX;
        return rst;
    }
};
