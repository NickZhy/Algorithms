class Solution {
public:
    int titleToNumber(string s) {
        int rst = 0;
        for(char ch: s) {
            rst *= 26;
            rst += ch - 'A' + 1;
        }
        return rst;
    }
};