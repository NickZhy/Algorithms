class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        int s = 0, e = n;
        while(s + 1 < e) {
            long mid = s + (e - s) / 2;
            long num = mid * (mid + 1) / 2;
            if(num == n) return mid;
            if(num < n) {
                s = mid;
            } else {
                e = mid;
            }
        }
        return s;
    }
};