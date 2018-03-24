class Solution {
public:
    bool check(vector<string>& strs, int pos) {
        if(!strs.size()) return false;
        if(strs[0].size() <= pos) return false;
        char ch = strs[0][pos];
        for(int i = 1; i < strs.size(); ++i)
            if(strs[i].size() <= pos || strs[i][pos] != ch) return false;
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        int len = 0;
        while(check(strs, len)) ++len;
        return strs[0].substr(0, len);
    }
};