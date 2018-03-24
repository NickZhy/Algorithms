class Solution {
    vector<int> buildTable(string& needle) {
        int len = needle.size();
        vector<int> dp(len, 0);
        int maxLen = 0;
        for(int i = 1; i < len; ++i) {
            while(maxLen > 0 && needle[i] != needle[maxLen]) 
                maxLen = dp[maxLen - 1];
            if(needle[i] == needle[maxLen])
                ++maxLen;
            dp[i] = maxLen;
        }
        return dp;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> tb = buildTable(needle);
        int start = 0, pos = 0;
        while(start + pos < haystack.size()) {
            if(haystack[start + pos] == needle[pos]) {
                ++pos;
                if(pos == needle.size()) 
                    return start;
            } else {
                if(pos == 0) {
                    ++start;
                } else if(tb[pos - 1] == 0) {
                    start += pos;
                    pos = 0;
                } else {
                    start += pos - tb[pos - 1];
                    pos = tb[pos - 1];
                }
            }
        }
        return -1;
    }
};