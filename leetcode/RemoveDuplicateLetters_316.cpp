class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<char> hasChar(256, false);
        for(char ch: s) ++dict[ch];
        string rst = '\0' + "";
        
        for(char ch: s) {
            --dict[ch];
            if(hasChar[ch]) continue;
            hasChar[ch] = true;
            while(ch < rst.back() && dict[rst.back()]) { 
                hasChar[rst.back()] = false;
                rst.pop_back();
            }
            rst += ch;
        }
        return rst;
    }
};