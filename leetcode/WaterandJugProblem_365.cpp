class Solution {
public:
    int gcd(int x, int y) {
        return x? gcd(y % x, x): y;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(!z) return true;
        if(x + y < z) return false;
        return z % gcd(x, y) == 0;
    }
};