class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); ++i) {
            int tmp = c - i * i;
            int sqTmp = sqrt(tmp);
            if(sqTmp * sqTmp == tmp) 
                return true;
        }
        return false;
    }
};