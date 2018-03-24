class Solution {
public:
    string toHex(int num) {
        string hex = "0123456789abcdef";
        string rst = "";
        unsigned int n = num;
        while(n) {
            int t = n & 0xf;
            rst += hex[t];
            n >>= 4;
        }
        reverse(rst.begin(), rst.end());
        if(!rst.size()) return "0";
        return rst;
    }
};