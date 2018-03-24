class Solution {
public:
    double pww(double x, long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0) {
            n = -n;
            x = 1/x;
        }
        double rst = myPow(x, n / 2);
        if(n % 2 == 1) {
            return rst * rst * x;
        }
        return rst * rst;
    }
    double myPow(double x, int n) {
        return pww(x, n);
    }
};