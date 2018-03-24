class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (!len) return "";
        vector<bool> dp(len, false);
        int start = 0, end = 0;
        for(int i = len - 2; i >= 0; --i) {
            for(int j = len - 1; j > i; --j) {
                if(s[i] == s[j]){
                    if(j <= i + 2){
                        dp[j] = true;
                    } else {
                        dp[j] = dp[j - 1];
                    }
                    if(dp[j] && j - i > end - start) {
                        start = i;
                        end = j;
                    }
                } else {
                    dp[j] = false;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};