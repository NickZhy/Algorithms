class Solution {
public:
    int myAtoi(string str) {
        long rst = 0;
        int idx = 0;
        while(idx < str.size() && str[idx] == ' ') ++idx;
        if(idx >= str.size()) return 0;
        
        bool sign = true;
        if(str[idx] == '+' || str[idx] == '-') {
            sign = (str[idx] == '+');
            ++idx;
        }
        
        while(idx < str.size() && str[idx] >= '0' && str[idx] <= '9') {
            rst *= 10;
            rst += str[idx++] - '0';
            if(rst > INT_MAX) return sign? INT_MAX: INT_MIN;
        }
        if(sign) return rst;
        return -rst;
    }
};