class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s2t[256] = {0};
        char t2s[256] = {0}; 
        for(int i = 0; i < s.size(); ++i) {
            int idx1 = s[i];
            int idx2 = t[i];
            if(!s2t[idx1] && !t2s[idx2]) {
                s2t[idx1] = idx2;
                t2s[idx2] = idx1;
            }
            if(s2t[idx1] != idx2 || idx1 != t2s[idx2]) return false;
        }
        return true;
    }
};