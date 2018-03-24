class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int rst = 0, mask = 1 << 30;
        while(mask) {
            while(mask && !(mask & m) && !(mask & n)) 
                mask >>= 1;
            if((mask & n) && (mask & m)) {
                rst |= mask;
            } else {
                return rst;
            }
            mask >>= 1;
        }
        return rst;
    }
};