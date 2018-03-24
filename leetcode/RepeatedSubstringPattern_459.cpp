class Solution {
public:
    bool checkPattern(string& s, int len) {
        if(len == s.size()) return false;
        string head = s.substr(0, len);
        for(int i = len; i < s.size(); i += len) {
            if(head != s.substr(i, len)) return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i = 1; i <= sqrt(len); ++i) {
            if(len % i == 0) {
                if(checkPattern(s, i) || checkPattern(s, len / i)) 
                    return true;
            }
        }
        return false;
    }
};