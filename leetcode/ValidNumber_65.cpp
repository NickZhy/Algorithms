class Solution {
public:
    bool isDigit(string& s, int& pos) {
        return s[pos] >= '0' && s[pos] <= '9';
    }
    
    int parseUint(string& s, int& pos) {
        int val = 0;
        while(isDigit(s, pos)) {
            val = val * 10;
            val += s[pos++] - '0';
        }
        return val;
    }
    
    void skipSpace(string& s, int& pos) {
        while(s[pos] == ' ' && pos < s.size()) ++pos;
    }
    // a number can be represent as: (sign){uint(.)(uint)|.uint}(e(sign)uint)
    bool isNumber(string s) {
        if(!s.size())
            return false;
        int pos = 0;
        skipSpace(s, pos);
        // init our values
        int num1 = -1, num2 = -1, num3 = -1;
        int sign1 = 1, sign2 = 1;

        if(s[pos] == '-' || s[pos] == '+')
            sign1 = s[pos++] == '+' ? 1: -1;
        if(isDigit(s, pos))
            num1 = parseUint(s, pos);
        
        if(s[pos] == '.') ++pos;
        
        if(isDigit(s, pos))
            num2 = parseUint(s, pos);
        
        // We should parse at least one uint till now.
        if(num1 == -1 && num2 == -1)
            return false;
        
        if(s[pos] == 'e') {
            ++pos;
            if(s[pos] == '-' || s[pos] == '+')
                sign1 = s[pos++] == '+' ? 1: -1;
            // if 'e' exits, an uint must exit too.
            if(isDigit(s, pos)) 
                num3 = parseUint(s, pos);
            else 
                return false;
        }

        skipSpace(s, pos);
        // If it failed to reach the end of string, return false.
        if(pos != s.size())
            return false;
        return true;
    }
};
