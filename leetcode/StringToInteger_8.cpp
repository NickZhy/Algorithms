class Solution {
public:
    int myAtoi(string str) {
        if(!str.size()) return 0;
        bool sign = true;
        int i = 0;
        while(str[i] == ' ') ++i;
        if(str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '+');
    
        long num = 0;
        while(i < str.size() && num <= INT_MAX) {
            char ch = str[i++];
            if(ch < '0' || ch > '9')
                break;
            
            num *= 10;
            num += ch - '0';
        }
        if(num > INT_MAX) {
            if(sign)
                return INT_MAX;
            else
                return INT_MIN;
        } else {
            if(sign)
                return num;
            else
                return -num;
        }
    }
};
