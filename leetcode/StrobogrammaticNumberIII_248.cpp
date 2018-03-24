class Solution {
    int lengthN(int n, bool zero) {
        if(n <= 0) return 1;
        if(n == 1) return 3;
        return pow(5, n / 2 - 1) * (zero? 5: 4) * (n % 2? 3: 1);
    }
    
    string trans(string& str) {
        const string tb = "01    9 86";
        int len = str.size();
        string rst = str.substr(0, (len + 1) / 2);
        for(int i = len / 2 - 1; i >= 0; --i)
            rst += tb[str[i] - '0'];
        return rst;
    }
    
    int smaller(string& bd) {
        int rst = 0, len = bd.size();
        const int tb[] = { 0, 1, 2, 2, 2, 2, 2, 3, 3, 4 };
        const set<char> dgs = {'0', '1', '6', '8', '9'};
        if(len == 1) {
            char ch = bd[0];
            return (ch >= '0') + (ch >= '1') + (ch >= '8');
        }
        
        for(int i = 1; i < len; ++i)
            rst += lengthN(i, false);
        
        // count strobogrammatics smaller than the input
        for(int i = 0; i < len / 2; ++i) {
            int tmp = (tb[bd[i] - '0'] - !i) * lengthN(len - 2 - i * 2, true);
            rst += tmp;
            if(!dgs.count(bd[i])) return rst;
        }
        
        // middle one
        if(len % 2) {
            char ch = bd[len / 2];
            rst += (ch > '0') + (ch > '1') + (ch > '8');
        }
        
        rst += (trans(bd) <= bd);
        return rst;
    }
public:
    int strobogrammaticInRange(string low, string high) {
        return max(0, smaller(high) - smaller(low) + (low == trans(low)));
    }
};