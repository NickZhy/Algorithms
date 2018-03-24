class Solution {
public:
    int KMPTable(string& str) {
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        tmp = str + "/n" + tmp;
        
        vector<int> table(tmp.size(), 0);
        for(int pos = 1, maxPreSuff = 0; pos<tmp.size(); ++pos) {
            while(maxPreSuff > 0 && tmp[pos] != tmp[maxPreSuff])
                maxPreSuff = table[maxPreSuff - 1];
            if(str[maxPreSuff] == tmp[pos])
                ++maxPreSuff;
            table[pos] = maxPreSuff;
        }
        return table[tmp.size()-1];
    }
    
    string shortestPalindrome(string s) {
        int len = KMPTable(s);
        string prefix = "";
        while(len < s.size()) {
            prefix += s[len++];
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};