class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        for(char ch: t) --target[ch];
        
        int len = s.size(), missing = t.size();
        if(!len) return "";
        if(!missing) return s.substr(0, 1);
        
        string result = "";
        int start = 0;
        for(int i = 0; i < len; ++i) {
            if(target[s[i]]++ < 0) --missing;
            while(target[s[start]] > 0) --target[s[start++]];
            if(!missing) {
                if(i - start + 1 < result.size() || result.size() == 0)
                    result = s.substr(start, i - start + 1);
                --target[s[start++]];
                ++missing;
            }
        }
        return result;
    }
};