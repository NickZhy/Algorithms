class Solution {
public:
    int sqt(int x, int s) {
        int y = x / s;
        if(abs(y - s) > 1) {
            return sqt(x, (s + y) / 2);
        }
        return min(s, y);
    }
    
    int mySqrt(int x) {
        if(x <= 1) return x;
        return sqt(x, x / 2);
    }
};