class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(256, 0);
        for(char ch: s) ++count[ch];
        for(int i = 0; i < s.size(); ++i) 
            if(count[s[i]] == 1) return i;
        return -1;
    }
};