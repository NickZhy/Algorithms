class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        int window[256] = {0};
        int charNum = 0;
        int start = 0, end = 0, maxLen = 0;
        while(end < s.size()) {
            char ch = s[end];
            if(window[ch] > 0 || charNum < k) {
                charNum += (window[ch] == 0);
                ++window[ch];
                ++end;
            } else {
                maxLen = max(maxLen, end - start);
                while(charNum == k) {
                    char t = s[start++];
                    --window[t];
                    if(!window[t])
                        --charNum;
                }
            }
        }
        maxLen = max(maxLen, end - start);
        return maxLen;
    }
};