class Solution {
public:
    bool readNum(string s, int& pos) {
        bool rst = false;
        while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
            ++pos;
            rst = true;
        }
        return rst;
    }
    
    bool readSignNum(string s, int& pos) {
        if(pos == s.size()) return false;
        if(s[pos] == '+' || s[pos] == '-') ++pos;
        return readNum(s, pos);
    }
    
    bool readFloatNum(string s, int& pos) {
        if(pos == s.size()) return false;
        bool hasNum = readSignNum(s, pos);
        if(pos < s.size() && s[pos] == '.') {
            bool tail = readNum(s, ++pos);
            return hasNum? true: tail;
        }
        return hasNum;
    }
    
    bool isNumber(string s) {
        while(s.size() && s.back() == ' ') s.pop_back();
        int pos = 0;
        while(pos < s.size() && s[pos] == ' ') ++pos;
        
        bool hasNum = readFloatNum(s, pos);

        if(pos < s.size() && s[pos] == 'e') {
            if(!hasNum) return false;
            bool hasExp =  readSignNum(s, ++pos);
            return pos == s.size() && hasExp;
        }
        return pos == s.size() && hasNum;
    }
};