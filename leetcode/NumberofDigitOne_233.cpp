class Solution {
    unordered_map<int, int> reg;
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        if(n < 10) return 1;
        if(reg.count(n)) return reg[n];
        long div = 1;
        while(n / (10 * div))
            div *= 10;
        int fst = n / div;
        int rst = 0;
        for(int i = 0; i < fst; ++i) {
            if(i == 1) rst += div;
            rst += countDigitOne(div - 1);
        }
        if(fst == 1) rst += n - div * fst + 1;
        rst += countDigitOne(n - div * fst);
        reg[n] = rst;
        return rst;
    }
};