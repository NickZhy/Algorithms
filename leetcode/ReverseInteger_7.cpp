class Solution {
public:
    int reverse(int x) {
        long rst = 0;
        bool sign = (x > 0);
        x = abs(x);
        while(x) {
            rst *= 10;
            rst += x % 10;
            x /= 10;
        }
        if(!sign) rst = -rst;
        if(rst < INT_MIN || rst > INT_MAX) return 0;
        return rst;
    }
};