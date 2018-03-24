class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sq = sqrt(num);
        int rst = 1;
        for(int i = 2; i <= sq; ++i) {
            if(num % i == 0) {
                rst += i;
                if(num / i != i) {
                    rst += num / i;
                }
                if(rst > num) return false;
            }
        }
        return rst == num;
    }
};