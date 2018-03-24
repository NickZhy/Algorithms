class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int pos = 0, sLen = s.size(), tLen = t.size();
        if(abs(sLen - tLen) > 1) return false;
        while(pos < sLen && s[pos] == t[pos]) ++pos;
        if(sLen == tLen) {
            if(pos == sLen) return false;
            return s.substr(pos + 1) == t.substr(pos + 1);
        }
        if(sLen > tLen) return s.substr(pos + 1) == t.substr(pos);
        return t.substr(pos + 1) == s.substr(pos);
    }
};