class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> vecN;
        while(N) {
            int digit = N % 10;
            vecN.push_back(digit);
            N = N / 10;
        }
        int len = vecN.size();
        int tail9 = 0;
        for(int i = 1; i < len; ++i) {
            if(vecN[i] > vecN[i - 1]) {
                --vecN[i];
                tail9 = i;
            }
        }
        for(int i = 0; i < tail9; ++i)
            vecN[i] = 9;
        reverse(vecN.begin(), vecN.end());
        int rst = 0;
        for(auto n: vecN) {
            rst *= 10;
            rst += n;
        }
        return rst;
    }
};