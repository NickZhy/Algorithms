class Solution {
public:
    int sqrt(int a, int b) {
        return abs(a / b - b) <= 1? b: sqrt(a, (a / b + b) / 2);
    }
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        if(num <= 1) return true;
        int t = sqrt(num, num / 2);
        return t*t == num;
    }
};